/**
 *  Propriétario: LogPyx
 *  Nome: uart.c
 *  Descrição: Trata funções relacionadas aos devices (periféricos), gerenciamento de conexão,
 *  configuração, infomarções sobre.  
 *  Referências:
 *  Desenvolvedor: Henrique Ferreira 
 */

#include "uart_header.h"

uart_config_t uart0_config = UART0_CONFIG_DEFAULT();
uart_config_t uart1_config = UART1_CONFIG_DEFAULT();

int intr_alloc_flags =0;

///////////////////////////////////////////////////////////////////////////////////
// Função: uart_Init(uint8_t uart);
// Descrição: Verifica se o device conectado possui um decawaveID válido.
// Argumentos: uint8_t uart -> UART0_INSTANCE
//                             UART1_INSTANCE
// Retorno:    void 
//////////////////////////////////////////////////////////////////////////////////
void uartInit(){
    uart_driver_install(UART0_INSTANCE, UART_BUFFER_SIZE * 2, 0, 0, NULL, intr_alloc_flags);
    uart_param_config(UART0_INSTANCE, &uart0_config);
    uart_set_pin(UART0_INSTANCE, UART0_PIN_TX, UART0_PIN_RX, -1, -1);

    uart_driver_install(UART1_INSTANCE, UART_BUFFER_SIZE * 2, 0, 0, NULL, intr_alloc_flags);
    uart_param_config(UART1_INSTANCE, &uart1_config);
    uart_set_pin(UART1_INSTANCE, UART1_PIN_TX, UART1_PIN_RX, -1, -1);
}

///////////////////////////////////////////////////////////////////////////////////
// Função: uartSendData(uint8_t uartInstace, uint8_t *data, uint8_t lenght);
// Descrição: Verifica se o device conectado possui um decawaveID válido.
// Argumentos: uint8_t uart -> UART0_INSTANCE
//                             UART1_INSTANCE
// Retorno:    void 
//////////////////////////////////////////////////////////////////////////////////
uint8_t uartSendData(uint8_t uartInstace, char *data, uint8_t length) {
    // Write data back to the UART
    return uart_write_bytes(uartInstace, data, length);
}

///////////////////////////////////////////////////////////////////////////////////
// Função: uartReadData(uint8_t uartInstace, uint8_t *data, uint8_t tam);
// Descrição: Verifica se o device conectado possui um decawaveID válido.
// Argumentos: uint8_t uart   -> UART0_INSTANCE
//                               UART1_INSTANCE
//             uint8_t * data -> buffer para recepeção de dados 
// Retorno:    void 
//////////////////////////////////////////////////////////////////////////////////
uint8_t uartReadData(uint8_t uartInstace, uint8_t *data){
    int len = uart_read_bytes(uartInstace, data, UART_BUFFER_SIZE-1, pdMS_TO_TICKS(50));
    return len;
}

// Função para verificar a disponibilidade de bytes na UART
size_t uartAvailable() {
    size_t available_bytes = 0;
    uart_get_buffered_data_len(UART1_INSTANCE, &available_bytes);
    return available_bytes;
}

// Função para descartar todos os bytes disponíveis na UART
void uartFlush() {
    uart_flush_input(UART1_INSTANCE);
}