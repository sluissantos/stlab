/**
 * @file gsmModem.c
 * @author Luis Santos (luis.santos@logpyx.com)
 * @brief 
 * 
 * @version 1.0.0
 * @date 2024-05
 * 
 * @attention
 * 
 * <h2><center>&copy; COPYRIGHT 2023 LogPyx S/A</center></h2>
 * 
 */

#include "gsmModem.h"

static gsm_modem_config_t gsm_modem_config;

static uint8_t gsmModemAnswer[UART_BUFFER_SIZE];
static char commandModem[256];

static char messageMqtt[512];

/**
 * @brief Verifica se o IP foi obtido
 * @param answer buffer de resposta a ser analisado
 * @retval bool de retorno. Caso verdadeiro, preenche a variável IP
 */
bool gsmModemVerifyIP(uint8_t *answer) {
    char *token = strtok((char *)answer, "\r\n");
    while (token != NULL) {
        if (strstr(token, "+CNACT") != NULL && strstr(token, ",1,") != NULL) {
            char *ip_start = strstr(token, "\"");
            if (ip_start != NULL) {
                ip_start++;
                char *ip_end = strstr(ip_start, "\"");
                if (ip_end != NULL) {
                    size_t ip_length = ip_end - ip_start;
                    strncpy(gsm_modem_config.gsm_modem_ip, ip_start, ip_length);
                    ESP_LOGI(TAG_MODEM, "IP MODEM: %s", gsm_modem_config.gsm_modem_ip);
                }
            }
            return true;
        }
        token = strtok(NULL, "\r\n");
    }
    return false;
}

/**
 * @brief Função que retorna o valor de uma posição de token de uma linha
 * @param None
 * @retval *answer   -   linha 
 * @retval position  -   posição do token
 * @retval *value    -   retorno
 */
void gsmModemGetValue(const char *answer, int position, double *value) {
    int comma_count = 0;
    const char *start_ptr = NULL;

    for (const char *p = answer; *p != '\0'; p++) {
        if (*p == ',') {
            comma_count++;
            if (comma_count == position) {
                start_ptr = p + 1;
                break;
            }
        }
    }

    if (start_ptr != NULL) {
        char value_str[20] = {0};
        const char *end_ptr = strchr(start_ptr, ',');
        if (end_ptr != NULL) {
            strncpy(value_str, start_ptr, end_ptr - start_ptr);
        } else {
            strncpy(value_str, start_ptr, strlen(start_ptr));
        }
        if (*value_str != '\0') {
            *value = atof(value_str);
        }
    }
}

/**
 * @brief Função que retorna a string de um retorno, separada por '\n'
 * @param None
 * @retval *answer   -   linha 
 * @retval position  -   posição do token
 * @retval *str    -   retorno
 */
void gsmModemGetStr(const char *answer, int position, char *str) {
    int line_count = 0;
    const char *start_ptr = NULL;

    for (const char *p = answer; *p != '\0'; p++) {
        if (*p == '\n') {
            line_count++;
            if (line_count == position) {
                start_ptr = p + 1;
                break;
            }
        }
    }
    if (start_ptr != NULL) {
        const char *end_ptr = strchr(start_ptr, '\r');
        if (end_ptr != NULL) {
            strncpy(str, start_ptr, end_ptr - start_ptr);
            str[end_ptr - start_ptr] = '\0';
        } else {
            strcpy(str, start_ptr);
        }
    } else {
        *str = '\0';
    }
}

/**
 * @brief Realiza o envio do dado desejado
 * @param data buffer contendo o dado que se deseja enviar
 * @retval none
 */
void gsmModemSendData(char *data) {
    #ifdef GSM_MODEM_LOG_MODEM_SEND
        ESP_LOGI(TAG_MODEM, ".%s", data);
    #endif
    uartSendData(UART1_INSTANCE, data, strlen(data));
    return;
}

/**
 * @brief Lẽ o retorno do dado enviado
 * @param modemAnswer buffer de resposta
 * @retval bool booleando referente ao sucesso ou falha na leitura
 */
bool gsmModemWaitResponse(uint8_t *modemAnswer) {
    uint8_t gsmModemRetryReadUart = 0;
    while(gsmModemRetryReadUart < GSM_MODEM_RETRY_READ_UART){
        vTaskDelay(pdMS_TO_TICKS(50));
        if(uartReadData(UART1_INSTANCE, modemAnswer) > 0){
            return true;
        }
        gsmModemRetryReadUart++;
    }
    return false;
}

/**
 * @brief Realiza a rotina de envio de comandos e recebimento das respostas
 * @param data dado a ser enviado, independente de qual for
 * @param answer buffer de resposta do dado enviado descrito acima
 * @param answer_expected resposta esperada
 * @retval uint8_t retorno em cima da resposta esperada
 */
uint8_t gsmModemCommand(char *data, uint8_t *answer, const char *answer_expected) {
    vTaskDelay(pdMS_TO_TICKS(50));
    memset(answer, 0, UART_BUFFER_SIZE);
    uint8_t gsmModemRetrySendUart = 0;
    while(gsmModemRetrySendUart < GSM_MODEM_RETRY_SEND_UART) {
        gsmModemSendData(data);
        if(gsmModemWaitResponse(answer)){
            #ifdef GSM_MODEM_LOG_MODEM_READ
                ESP_LOGI(TAG_MODEM, "%s", answer);
            #endif
            
            if(strstr((const char*)answer, answer_expected) != NULL) {
                return GSM_MODEM_EXPECTED_ANSWER;
            } else{
                return GSM_MODEM_NO_EXPECTED_ANSWER;
            }
        }
        gsmModemRetrySendUart++;
        vTaskDelay(pdMS_TO_TICKS(500));
    }
    return GSM_MODEM_NO_ANSWER;
}

/**
 * @brief Realiza a inicialização dos pinos de configuração e power do modem
 * @param None
 * @retval None
 */
void gsmModemSetGpio(void) {
    gpio_config_t io_conf;
    // Configurar pinos de energia do modem e DTR como saída
    io_conf.pin_bit_mask = (1ULL << GSM_MODEM_PWR_PIN);
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE; //TEM QUE CONFERIR ISSO
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&io_conf);
    return;
}

/**
 * @brief Realiza um restart no modem
 * @param None
 * @retval None
 */
void gsmModemRestartModem(void) {
    /*
    gpio_set_level(GSM_MODEM_PWR_PIN, 0);
    vTaskDelay(pdMS_TO_TICKS(1000));
    */

    xpowerDeinit();
    return;
}

/**
 * @brief Realiza o startup do modem 
 * @param None
 * @retval None
 */
void gsmModemStartModem(void) {
    snprintf(commandModem, sizeof(commandModem), "%s%s", GMS_MODEM_AT, GSM_MODEM_NL);
    switch (gsmModemCommand(commandModem, gsmModemAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_MODEM, "Start modem failed. Restart modem and ESP.");
            gsmModemRestartModem();
            esp_restart();
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "Start modem successfully\n");
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "Start modem unsuccessfully\n");
            break;
    }
    return;
}

/**
 * @brief Verifica se o SIM Card está inserido
 * @param None
 * @retval None
 */
void gsmModemGetSimStatus(void) {
    snprintf(commandModem, sizeof(commandModem), "%s%s%s", GMS_MODEM_AT, "+CPIN?", GSM_MODEM_NL);
    switch (gsmModemCommand(commandModem, gsmModemAnswer, GSM_MODEM_READY)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_MODEM, "SIM Card error. Restart modem and ESP.");
            gsmModemRestartModem();
            esp_restart();
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "SIM Card READY\n");
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "SIM Card isn't READY\n");
            break;
    }
    return;
}

/**
 * @brief 
 * @param None
 * @retval none
 */
void gsmModemPdpContext(void) {
    snprintf(commandModem, sizeof(commandModem), "%s%s%s%s", GMS_MODEM_AT, "+CNCFG=", GMS_MODEM_DEFINE_PDP_CONTEXT, GSM_MODEM_NL);
    switch (gsmModemCommand(commandModem, gsmModemAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_MODEM, "PDP context error");
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "PDP context sucessfully");
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "PDP context unsucessfully");
            break;
    }
    return;
}

/**
 * @brief Definine o modo de rede
 * @param mode network mode
 * @retval None
 */
void gsmModemSetNetworkMode(uint8_t mode) {
    snprintf(commandModem, sizeof(commandModem), "%s%s%d%s", GMS_MODEM_AT, "+CNMP=", mode, GSM_MODEM_NL);
    switch (gsmModemCommand(commandModem, gsmModemAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_MODEM, "Set network mode error.");
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "Set network mode successfully\n");
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "Set network mode unsuccessfully\n");
            break;
    }
    return;
}

/**
 * @brief Definine a telemetria desejada
 * @param mode telemetria desejada
 * @retval none
 */
void gsmModemSetPreferredMode(uint8_t mode) {
    snprintf(commandModem, sizeof(commandModem), "%s%s%d%s", GMS_MODEM_AT, "+CMNB=", mode, GSM_MODEM_NL);
    switch (gsmModemCommand(commandModem, gsmModemAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_MODEM, "Set preferred mode error.");
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "Set preferred mode successfully\n");
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "Set preferred mode unsuccessfully\n");
            break;
    }
    return;
}

/**
 * @brief Get network mode APN
 * @param none
 * @retval none
 */
void gsmModemGetNetworkMode(void) {
    snprintf(commandModem, sizeof(commandModem), "%s%s%s", GMS_MODEM_AT, "+CGNAPN", GSM_MODEM_NL);
    switch (gsmModemCommand(commandModem, gsmModemAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_MODEM, "Get network mode error.");
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "Get network mode successfully\n");
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "Get network mode unsuccessfully\n");
            break;
    }
    return;
}

/**
 * @brief Retonar o status da conexão
 * @param none
 * @retval bool do retorno
 */
void gsmModemGetRegistrationStatus(void) {
    while (1){
        snprintf(commandModem, sizeof(commandModem), "%s%s%s", GMS_MODEM_AT, "+CEREG?", GSM_MODEM_NL);
        switch (gsmModemCommand(commandModem, gsmModemAnswer, GSM_MODEM_REGISTRATION_STATUS_XREG_OK_HOME)) {
            case GSM_MODEM_NO_ANSWER:
                ESP_LOGI(TAG_MODEM, "Get EPS network registration status error");
                break;
            
            case GSM_MODEM_EXPECTED_ANSWER:
                ESP_LOGI(TAG_MODEM, "Get EPS network registration status successfully\n");
                return;

            case GSM_MODEM_NO_EXPECTED_ANSWER:
                snprintf(commandModem, sizeof(commandModem), "%s%s%s", GMS_MODEM_AT, "+CGREG?", GSM_MODEM_NL);
                switch (gsmModemCommand(commandModem, gsmModemAnswer, GSM_MODEM_REGISTRATION_STATUS_XREG_OK_ROAMING)) {
                    case GSM_MODEM_NO_ANSWER:
                        ESP_LOGI(TAG_MODEM, "Get network registration status error");
                        break;
                    
                    case GSM_MODEM_EXPECTED_ANSWER:
                        ESP_LOGI(TAG_MODEM, "Get network registration status successfully\n");
                        return;

                    default:
                        ESP_LOGI(TAG_MODEM, "Get network registration status unsuccessfully\n");
                        break;
                }
                break;
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    return;
}

/**
 * @brief Função que realiza a conexão na rede
 * @param None
 * @retval bool de retorno do comando
 */
bool gsmModemGprsConnect(void) {
    snprintf(commandModem, sizeof(commandModem), "%s%s%s", GMS_MODEM_AT, "+CGATT?", GSM_MODEM_NL);
    switch (gsmModemCommand(commandModem, gsmModemAnswer, GSM_MODEM_GPRS_CONNECTED)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_MODEM, "Attached from GPRS service error");
            return false;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "Attached from GPRS service sucessfully");
            return true;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "Attached from GPRS service unsucessfully");
            return false;
    }
    return false;
}

/**
 * @brief Função que ativa a conexão na rede
 * @param None
 * @retval bool
 */
bool gsmModemAppNetworkActive(void) {
    snprintf(commandModem, sizeof(commandModem), "%s%s%s", GMS_MODEM_AT, "+CNACT?", GSM_MODEM_NL);
    gsmModemCommand(commandModem, gsmModemAnswer, GSM_MODEM_OK);
    uint8_t res = gsmModemVerifyIP(gsmModemAnswer);
    if(res == GSM_MODEM_IP_ADDRESS_OBTAINED){
        ESP_LOGI(TAG_MODEM, "App network active sucessfully");
        return true;
    } else{ //GSM_MODEM_IP_ADDRESS_NO_OBTAINED
        snprintf(commandModem, sizeof(commandModem), "%s%s%s", GMS_MODEM_AT, "+CNACT=0,1", GSM_MODEM_NL);
        switch (gsmModemCommand(commandModem, gsmModemAnswer, GSM_MODEM_OK)) {
            case GSM_MODEM_NO_ANSWER:
                ESP_LOGI(TAG_MODEM, "App network active error");
                return false;
            
            case GSM_MODEM_EXPECTED_ANSWER:
                ESP_LOGI(TAG_MODEM, "App network active sucessfully");
                return true;

            case GSM_MODEM_NO_EXPECTED_ANSWER:
                ESP_LOGI(TAG_MODEM, "App network active unsucessfully");
                return false;
        }
        return false;
    }
}

/**
 * @brief Função que realiza a leitura do IMEI
 * @param None
 * @retval none
 */
void gsmModemGetImei(void) {
    snprintf(commandModem, sizeof(commandModem), "%s%s%s", GMS_MODEM_AT, "+GSN", GSM_MODEM_NL);
    switch (gsmModemCommand(commandModem, gsmModemAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_MODEM, "Get IMEI error");
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "Get IMEI sucessfully");
            gsmModemGetStr((const char*)gsmModemAnswer, 1, gsm_modem_config.gsm_modem_imei);
            ESP_LOGI(TAG_MODEM, "IMEI = %s", gsm_modem_config.gsm_modem_imei);
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "Get IMEI unsucessfully");
            break;
    }
    return;
}

/**
 * @brief Verifica se o SIM Card está inserido
 * @param None
 * @retval None
 */
void gsmModemGetSignalQuality(void) {
    snprintf(commandModem, sizeof(commandModem), "%s%s%s", GMS_MODEM_AT, "+CSQ", GSM_MODEM_NL);
    switch (gsmModemCommand(commandModem, gsmModemAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_MODEM, "Get signal quality error");
            esp_restart();
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "Get signal quality successfully\n");
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MODEM, "Get signal quality unsuccessfully\n");
            break;
    }
    return;
}

/**
 * @brief Função get para um ponteiro gsm_modem_config
 * @param None
 * @retval *gsm_modem_config
 */
gsm_modem_config_t *gsmModemGetPointerConfig(void) {
    return &gsm_modem_config;
}

/**
 * @brief Função get para uma referência gsm_modem_config
 * @param None
 * @retval gsm_modem_config
 */
gsm_modem_config_t gsmModemGetConfig(void) {
    return gsm_modem_config;
}

/**
 * @brief Função de inicialização do componente gsmModem
 * @param None
 * @retval None
 */
void gsmModemStart(void) {   

    GSM_MODEM_CONFIG_DEFAULT(gsm_modem_config);

    gsmModemSetGpio();

    gsmModemStartModem();

    gsmModemGetSimStatus();

    return;
}

/**
 * @brief Função de inicialização da rede
 * @param None
 * @retval None
 */
void gsmModemInit(void) {   

    gsmModemSetNetworkMode(gsm_modem_config.gsm_modem_network_mode);
    
    gsmModemSetPreferredMode(gsm_modem_config.gsm_modem_preferred_mode);
    
    gsmModemGetRegistrationStatus();

    uint8_t res = gsmModemGprsConnect();

    gsmModemPdpContext();

    gsmModemAppNetworkActive();

    ESP_LOGI(TAG_MODEM, "GPRS status : %s\n", res? "connected" : "not connected");

    gsmModemGetNetworkMode();
    
    gsmModemGetImei();

    return;
}

/**
 * @brief Cria a mensagem de GPS
 * @param None
 * @retval message
 */
char *gsmModemCreateGpsMessage(void) {
    memset(messageMqtt, 0, sizeof(messageMqtt));
    ESP_LOGI(TAG_MODEM, "time = %s", gsmGpsGetCurrentTime());

    gsm_gps_config_t gsm_gps_config_modem = gsmGpsGetConfig();

    double lat_m = gsmGpsCalculaMediaDesvioPadrao(gsm_gps_config_modem.gsm_gps_coordenadas.latitudes);
    double lon_m = gsmGpsCalculaMediaDesvioPadrao(gsm_gps_config_modem.gsm_gps_coordenadas.longitudes);
    double vel_m = gsmGpsCalculaMediaDesvioPadrao(gsm_gps_config_modem.gsm_gps_coordenadas.speeds);
    
    snprintf(messageMqtt, sizeof(messageMqtt), "{\"lat_m\":%lf,\"lon_m\":%lf,\"lat_i\":%lf,\"lon_i\":%lf,\"vel_m\":%lf,\"vel_i\":%lf}", 
        lat_m,
            lon_m,
                gsm_gps_config_modem.gsm_gps_coordenadas.last_latitude,
                    gsm_gps_config_modem.gsm_gps_coordenadas.last_longitude,
                        vel_m,
                            gsm_gps_config_modem.gsm_gps_coordenadas.last_speed);
    ESP_LOGI(TAG_GPS, "\nlat_m = %lf. lon_m = %lf. lat_i = %lf. lon_i = %lf. vel_m = %lf. vel_i = %lf", 
        lat_m,
            lon_m,
                gsm_gps_config_modem.gsm_gps_coordenadas.last_latitude,
                    gsm_gps_config_modem.gsm_gps_coordenadas.last_longitude,
                        vel_m,
                            gsm_gps_config_modem.gsm_gps_coordenadas.last_speed);

    return messageMqtt;
}

/**
 * @brief Retorna o valor do sinal RSSI
 * @param None
 * @retval none
 */
void gsmModemGetCSQ(uint8_t *csq_value) {
    gsmModemGetSignalQuality();
    const char *csq_ptr = strstr((const char*)gsmModemAnswer, "+CSQ:");
    if (csq_ptr != NULL) {
        sscanf(csq_ptr, "+CSQ: %hhu", csq_value);
    }
}

/**
 * @brief Cria a mensagem de status
 * @param None
 * @retval message
 */
char *gsmModemCreateInfoMessage(void) {
    memset(messageMqtt, 0, sizeof(messageMqtt));
    if(strlen(gsm_modem_config.gsm_modem_ip) == 0) {
        gsmModemAppNetworkActive();
    }

    gsmModemGetCSQ(&gsm_modem_config.gsm_modem_signal);

    snprintf(messageMqtt, sizeof(messageMqtt), "{\"ip\":\"%s\",\"rssi\":%d,\"IMEI\":\"%s\"}", 
            gsm_modem_config.gsm_modem_ip, gsm_modem_config.gsm_modem_signal, gsm_modem_config.gsm_modem_imei);
    return messageMqtt;
}

/**
 * @brief Task de rotina do GPS e MQTT
 * @param None
 * @retval None
 */
void gsmModemNetworkTask(void *pvParameter) {
    static uint8_t flag_first_message = 1;
    static uint8_t ret;
    while(1) {
        /*!< MQTTS */
        gsmMqttConnect();

        if (flag_first_message) {
            ret = gsmMqttPublishMqtt("first-on", gsmMqttGetMqttConfigParam().topics_mqtt_config.publish_status);
            flag_first_message = 0;
        } else {
            ret = gsmMqttPublishMqtt("on", gsmMqttGetMqttConfigParam().topics_mqtt_config.publish_status);
        }

        if (ret) {
            ESP_LOGI(TAG_MODEM, "MQTT publish status successfully");
        } else {
            ESP_LOGI(TAG_MODEM, "MQTT publish status unsuccessfully");
        }

        gsmMqttDisconnect();

        vTaskDelay(pdMS_TO_TICKS(60000));
    }
}

