/**
 * @file communication.ino
 * @author Luis Santos (luis.santos@logpyx.com)
 * @author Henrique Ferreira (henrique.ferreira@logpyx.com)
 * @brief Esse arquivo apresenta as funções para gravação e leitura do buffer UART; 
 *          FUnções de empacotamento de pacotes e desempacotamentos de pacotes recebidos via UART;
 *              Variáveis internas;
 *                  Envio das mensagens MQTT.
 * 
 * @version 1.0.0
 * @date 2024-04
 * 
 * @attention
 * 
 * <h2><center>&copy; COPYRIGHT 2023 LogPyx S/A</center></h2>
 * 
 */

#include "communication.h"

uint8_t uartRxBuffer[COMM_BUFFER_UART_SIZE] = {0};

uint8_t txBuffer[COMM_BUFFER_UART_SIZE] = {0};

uint8_t rxBuffer[COMM_BUFFER_UART_SIZE] = {0};

uint8_t rxBufferState = 0; 

uint8_t rxBufferIndex = 0;

uint8_t rxBufferSize = 0;

uint8_t lengthDataUart = 0;

buffer_t uartBuffer = {                  /*!< Struct usada para definir os valores padrão do buffer BLE*/
    .maxlen = COMM_BUFFER_UART_SIZE,
    .size = 0,
    .head = 0,
    .tail = 0,
    .bufferUart = {0},
};

/**
 * @brief Realiza inserção de novos dados ao buffer circular
 * 
 * @param newData novo byte a ser adicionado
 * @return int8_t resultado da operação
 */
int8_t commBufferPush(void *newData){
    buffer_t *buffer = &uartBuffer;
    int8_t next;	
    uint8_t *data = (uint8_t *)newData;		

    next = buffer->head + 1;  // next is where head will point to after this Set.
    if (next >= buffer->maxlen)
        next = 0;

    if (next == buffer->tail)  // if the head + 1 == tail, circular buffer is full
        return -1;

    buffer->bufferUart[buffer->head] = *data;  // Load data and then move

    buffer->head = next;             // head to next data offset

    return 0; // return success to indicate successful push.
}

/**
 * @brief Realiza o cálculo de check sum para validação do pacote
 * de dados recebidos
 * 
 * @param length tamanho do buffer
 * @param data buffer de dados recebidos
 * @return uint8_t resultado da operação
 */
uint8_t calculaCheckSum(uint8_t length, uint8_t *data) {
    uint8_t i = 0;
    uint8_t CheckSum = 0;
    for(i = 0; i < length ; i++) 
        CheckSum += data[i];
    // Retorna com valor check sum calculado
    return(CheckSum);
}

/**
 * @brief Remove os dados do buffer circular para serem formatados pela função commMontaPacote()
 * 
 * @param buffer buffer em que os dados estão salvos
 * @param data byte removido do buffer circular
 * @return int8_t resultado da operação
 */
int8_t commBufferPop(buffer_t * buffer, void *var){
    uint8_t *data = (uint8_t *)var;
    int8_t next;
    if (buffer->head == buffer->tail)  // if the head == tail, we don't have any data
        return -1;

    next = buffer->tail + 1;  // next is where tail will point to after this read.
    if((next >= buffer->maxlen))
        next = 0;

    *data = buffer->bufferUart[buffer->tail];  // Read data and then move

    buffer->tail = next;              // tail to next offset.
    return 0;  // return success to indicate successful push.
}

/**
 * @brief Realiza o processamento do comando inserido no pacote de dados
 * 
 * @param newData pacote de dados
 * @param newDataTam tamanho do pacote de dados
 * @retval None
 */
void commTrataComando(uint8_t *newData, uint8_t newDataTam) {
    for(uint8_t i = 0; i < newDataTam; i++){
        ESP_LOGI(TAG_COMM, "BYTE %d : %02X", i, newData[i]);
    }
    
    switch (newData[0]){
        case WR_GENERIC_OPCODE: {
            /*
            if (newData[1] == WR_GENERIC_DISTANCE_OPCODE){
                    uint16_t tag = newData[4] << 8 | newData[5];
                    uint16_t dist = newData[6] << 8 | newData[7];
                    char payload1[64];
                    sprintf(payload1, "{\"tag\":\"%.4X\", \"dist\":%d}", tag, dist);
                    strcat(payload1, GSM_MODEM_NL);
                    gsmMqttPublishMqtt(payload1, gsmMqttGetMqttConfigParam().topics_mqtt_config.publish_generic);
            } else{
                char payload[(newDataTam - 1) * 2 + 3]; // +1 para o caractere nulo terminador
                for(uint8_t i = 1; i < newDataTam; i++){
                    sprintf(&payload[(i - 1) * 2], "%02X", newData[i]);
                }
                strcat(payload, GSM_MODEM_NL);
                gsmMqttPublishMqtt(payload, gsmMqttGetMqttConfigParam().topics_mqtt_config.publish_generic);
            }
            */  
            char payload[(newDataTam - 1) * 2 + 3]; // +1 para o caractere nulo terminador
            for(uint8_t i = 1; i < newDataTam; i++){
                sprintf(&payload[(i - 1) * 2], "%02X", newData[i]);
            }
            strcat(payload, GSM_MODEM_NL);
            gsmMqttPublishMqtt(payload, gsmMqttGetMqttConfigParam().topics_mqtt_config.publish_generic);
            break;
        }
        
            default:
                break;
    }
}


/**
 * @brief Realiza a formatação do pacote de dados recebido pelas interfaces
 * de comunicação UART e Bluetooth
 * 
 * @param ByteLido 
 * @retval None
 */
void commMontaPacote(uint8_t ByteLido){
    uint8_t chkSum = 0;
    
    //  Decodificacao do frame recebido
    //	------------------------------------------------------
    // Le cada byte do buffer circular da Uart, e monta os 
    // pacotes recebidos em um buffer local: new_pacote.
    //
    // rxBufferState assume os seguites valores:
    // 0 = Estado inicial
    // 1 = Recebeu start bit     
    // 2 = Recebeu tamanho do frame
    // 3 = Recebeu dado
    // 4 = Recebeu chkSum, dado disponivel, new pacote 
    // 5 ao 255 = Reservado
    // Ao final do frame recebido, chama o metodo 
    // TrataPacote, que decodifica o frame
    //	------------------------------------------------------

    switch(rxBufferState) {
        case START_BUFFER: 
            if (ByteLido == STX) 
                rxBufferState = BUFFER_SIZE;
        break;  
        
        case BUFFER_SIZE: 
            rxBufferIndex = 0;
            if (ByteLido <= COMM_BUFFER_UART_SIZE) {
                rxBufferSize = ByteLido;
                rxBufferState = FILLING_IN;   
            } 
            else rxBufferState = BUFFER_SIZE;		
        break;
        	
        case FILLING_IN:
            rxBuffer[rxBufferIndex] = ByteLido;
            rxBufferIndex++;
            if (rxBufferIndex >= rxBufferSize)
                rxBufferState = CHECK_SUM;    	
        break; 
                                    
        case CHECK_SUM:
            chkSum = calculaCheckSum(rxBufferSize, rxBuffer);
            rxBufferState = (chkSum == ByteLido) ? END_BUFFER : START_BUFFER;	
        break;

        case END_BUFFER:
            if (ByteLido == RTX) {
                // Chama o metodo TRATAPACOTE para decodificar o frame
                commTrataComando(rxBuffer, rxBufferSize);
                rxBufferState = START_BUFFER;
            } else {
                rxBufferState = START_BUFFER;
            }
            break;

        default:
            rxBufferState = START_BUFFER;
        break;
    }
}

/**
 * @brief Realiza a leitura dos bytes do buffer circular para posterior formatação
 * 
 * @param None
 * @retval None
 */
void commDowngradeBufferUART(void){
    uint8_t byte;
    while(commBufferPop(&uartBuffer,&byte) == 0){
        //ESP_LOGI("COMM_TAG","RxBuffer: %x",byte);
        commMontaPacote(byte);
    }
    return;
}

/**
 * @brief Realiza a leitura da porta UART para formatação dos dados pela função commMontaPacote()
 * 
 * @param None
 * @retval None
 */
void commUpdateBufferUart(){
    lengthDataUart = uartReadData(UART0_INSTANCE, uartRxBuffer);
    //ESP_LOGI(TAG_COMM,"uartRxBufferLength: %x",lengthDataUart);
    //esp_log_buffer_hex("Revo:",uartRxBuffer,lengthDataUart);
    for(uint8_t i = 0; i < lengthDataUart; i++){
        commBufferPush(&uartRxBuffer[i]);
    }
}

/**
 * @brief Task para atualizar o buffer dos dados recebidos pela interface UART ou Bluetooth
 * 
 * @param pvParameter parâmetros de chamada da task
 * @retval None
 */
void commUpdateBufferTask(void * pvParameter){
    while(1){
        commUpdateBufferUart();
        taskYIELD();
    }
}