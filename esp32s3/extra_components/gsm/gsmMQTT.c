/**
 * @file gsmMQTT.c
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

#include "gsmMQTT.h"

gsm_mqtt_config_param_t gsm_mqtt_config_param;

static uint8_t gsmMqttAnswer[UART_BUFFER_SIZE] = {0};
static char commandMqtt[UART_BUFFER_SIZE];

/**
 * @brief Função que verifica o estado de conexão com o broker
 * @param None
 * @retval bool flag conexão
 */
bool gsmMqttConnectedMqtt(void) {
    snprintf(commandMqtt, sizeof(commandMqtt), "%s%s%s", GMS_MODEM_AT, "+SMSTATE?", GSM_MODEM_NL);
    switch (gsmModemCommand(commandMqtt, gsmMqttAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_MQTT, "MQTT disconnected error");
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            return true;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MQTT, "MQTT not connected\n");
            break;
    }
    return gsmMqttConnect();
}

/**
 * @brief Função que realiza o envio do comando de publish e da mensagem a ser publicada
 * @param None
 * @retval bool flag sucesso ou falha no envio
 */
bool gsmMqttPublishMqtt(char *message, char *topic) {
    if(gsmMqttConnectedMqtt()){
        snprintf((char *)commandMqtt, sizeof(commandMqtt), "%s%s\"%s\",%d,1,1%s", GMS_MODEM_AT, "+SMPUB=", topic, strlen(message), GSM_MODEM_NL);
        switch(gsmModemCommand(commandMqtt, gsmMqttAnswer, GSM_MODEM_SIGNAL)){
            case GSM_MODEM_NO_ANSWER:
                ESP_LOGI(TAG_MQTT, "MQTT publish error");
                return false;

            case GSM_MODEM_EXPECTED_ANSWER:
                if(gsmModemCommand(message, gsmMqttAnswer, message) == GSM_MODEM_EXPECTED_ANSWER){
                    return true;
                }

            default:
                ESP_LOGI(TAG_MQTT, "MQTT publish failed");
                return false;
        }
    }
    return false;
}

/**
 * @brief Função que faz a desconexão com o broker mqtt
 * @param None
 * @retval None
 */
void gsmMqttDisconnect(void) {
    snprintf(commandMqtt, sizeof(commandMqtt), "%s%s%s", GMS_MODEM_AT, "+SMDISC", GSM_MODEM_NL);
    switch (gsmModemCommand(commandMqtt, gsmMqttAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_MQTT, "MQTT disconnected error");
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MQTT, "MQTT disconnected successfully\n");
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_MQTT, "MQTT disconnected unsuccessfully\n");
            break;
    }
    vTaskDelay(pdMS_TO_TICKS(1000));
    return;
}

/**
 * @brief Função de inicialização das configurações do broker
 * @param None
 * @retval None
 */
void gsmMqttConfigBroker(void) {
    /*<! Broker clientid */
    snprintf(commandMqtt, sizeof(commandMqtt), "%s%s\"%s\",\"%s\"%s", 
            GMS_MODEM_AT, "+SMCONF=", "CLIENTID", gsmModemGetConfig().gsm_modem_imei, GSM_MODEM_NL);
    gsmModemCommand(commandMqtt, gsmMqttAnswer, GSM_MODEM_OK);

    /*<! Broker URL */
    snprintf(commandMqtt, sizeof(commandMqtt), "%s%s\"%s\",\"%s\",%d%s", 
            GMS_MODEM_AT, "+SMCONF=", "URL", gsm_mqtt_config_param.broker_mqtt_config.broker_url_mqtt, 
                    gsm_mqtt_config_param.broker_mqtt_config.broker_port_mqtt, GSM_MODEM_NL);
    gsmModemCommand(commandMqtt, gsmMqttAnswer, GSM_MODEM_OK);

    /*<! Broker user */
    snprintf(commandMqtt, sizeof(commandMqtt), "%s%s\"%s\",\"%s\"%s", 
            GMS_MODEM_AT, "+SMCONF=", "USERNAME", gsm_mqtt_config_param.broker_mqtt_config.broker_user_mqtt, GSM_MODEM_NL);
    gsmModemCommand(commandMqtt, gsmMqttAnswer, GSM_MODEM_OK);

    /*<! Broker password */
    snprintf(commandMqtt, sizeof(commandMqtt), "%s%s\"%s\",\"%s\"%s", 
            GMS_MODEM_AT, "+SMCONF=", "PASSWORD", gsm_mqtt_config_param.broker_mqtt_config.broker_password_mqtt, GSM_MODEM_NL);
    gsmModemCommand(commandMqtt, gsmMqttAnswer, GSM_MODEM_OK);

    /*<! Broker clean session */
    snprintf(commandMqtt, sizeof(commandMqtt), "%s%s\"%s\",%d%s", 
            GMS_MODEM_AT, "+SMCONF=", "CLEANSS", gsm_mqtt_config_param.broker_mqtt_config.broker_clean_session, GSM_MODEM_NL);
    gsmModemCommand(commandMqtt, gsmMqttAnswer, GSM_MODEM_OK);

    /*<! Broker QOS */
    snprintf(commandMqtt, sizeof(commandMqtt), "%s%s\"%s\",%d%s", 
            GMS_MODEM_AT, "+SMCONF=", "QOS", gsm_mqtt_config_param.broker_mqtt_config.broker_qos_mqtt, GSM_MODEM_NL);
    gsmModemCommand(commandMqtt, gsmMqttAnswer, GSM_MODEM_OK);
    
    /*<! Broker retain */
    snprintf(commandMqtt, sizeof(commandMqtt), "%s%s\"%s\",%d%s", 
            GMS_MODEM_AT, "+SMCONF=", "RETAIN", gsm_mqtt_config_param.broker_mqtt_config.broker_retain, GSM_MODEM_NL);
    gsmModemCommand(commandMqtt, gsmMqttAnswer, GSM_MODEM_OK);
    
    /*<! Broker keepalive */
    snprintf(commandMqtt, sizeof(commandMqtt), "%s%s\"%s\",%d%s", 
            GMS_MODEM_AT, "+SMCONF=", "KEEPTIME", gsm_mqtt_config_param.broker_mqtt_config.broker_keepalive_mqtt, GSM_MODEM_NL);
    gsmModemCommand(commandMqtt, gsmMqttAnswer, GSM_MODEM_OK);

    snprintf(commandMqtt, sizeof(commandMqtt), "%s%s%s", GMS_MODEM_AT, "+SMCONF?", GSM_MODEM_NL);
    gsmModemCommand(commandMqtt, gsmMqttAnswer, GSM_MODEM_OK);

    return;
}

/**
 * @brief Função que efetiva a conexão com o broker
 * @param None
 * @retval bool connection status
 */
bool gsmMqttConnect(void) {
    uint8_t cont = 0;
    while(cont<GSM_MQTT_MAX_MQTT_CONNECTION_RETRY){
        snprintf(commandMqtt, sizeof(commandMqtt), "%s%s%s", GMS_MODEM_AT, "+SMCONN", GSM_MODEM_NL);
        switch (gsmModemCommand(commandMqtt, gsmMqttAnswer, GSM_MODEM_OK)) {
            case GSM_MODEM_NO_ANSWER:
                ESP_LOGI(TAG_MQTT, "MQTT Client connect error");
                break;
            
            case GSM_MODEM_EXPECTED_ANSWER:
                ESP_LOGI(TAG_MQTT, "MQTT Client connected");
                return true;

            case GSM_MODEM_NO_EXPECTED_ANSWER:
                ESP_LOGI(TAG_MQTT, "MQTT Client no connected");
                break;
        }
        cont++;
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    gsmModemRestartModem();
    esp_restart();
    return false;
}

/**
 * @brief Função de retorno da struct de configurações do MQTT
 * @param None
 * @retval None
 */
gsm_mqtt_config_param_t gsmMqttGetMqttConfigParam(void) {
    return gsm_mqtt_config_param;
}

/**
 * @brief Função de inicialização do componente gsmMQTT
 * @param None
 * @retval None
 */
void gsmMqttInit(void) {

    GSM_MQTT_CONFIG_PARAM_DEFAULT(gsm_mqtt_config_param, gsmModemGetPointerConfig()->gsm_modem_imei);

    gsmMqttDisconnect();

    gsmMqttConfigBroker();

    //gsmMqttConnect();

    return;
}
