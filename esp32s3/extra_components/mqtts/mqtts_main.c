/**
 * @file mqtts_main.c
 * @author Luis Santos (luis.santos@logpyx.com)
 * @brief Componente responsável pela conexão MQTT como o broker
 * 
 * @version 2.0.0
 * @date 2024-03
 * 
 * @attention
 * 
 * <h2><center>&copy; COPYRIGHT 2023 LogPyx S/A</center></h2>
 * 
 */

#include "mqtts_headers.h"

mqtt_config_param_t mqtt_config_param;
size_t mqtt_config_param_size = sizeof(mqtt_config_param_t);

static esp_mqtt_client_handle_t client;     /*!< Handle do cliente MQTT */
static bool flag_connected = false;         /*!< Flag de conexão com o broker */

/**
 * @brief Função intermediária para publicação de mensagens via MQTT para o broker
 * 
 * @param message   ponteiro para uma string contendo a mensagem a ser enviada
 * @param topic     ponteiro para uma string contendo o tópico a ser enviado
 * @return none
 */
void mqttPublishMessage(char *message, char *topic){
    ESP_LOGI(TAG_MQTTS, "publish message = %s", message);
    //esp_mqtt_client_publish(client, topic, message, strlen((char *)message), 
    //        mqtt_config_param.broker_mqtt_config.broker_qos_mqtt, mqtt_config_param.broker_mqtt_config.broker_retain);
    //ESP_LOGI(TAG_MQTTS, "[APP] Free memory: %" PRIu32 " bytes", esp_get_free_heap_size());
    return;
}

/**
 * @brief Handle de conexão e status MQTT
 * 
 * @param none
 * @return none
 */
static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data){
    ESP_LOGD(TAG_MQTTS, "Event dispatched from event loop base=%s, event_id=%ld", base, event_id);
    esp_mqtt_event_handle_t event = (esp_mqtt_event_handle_t)event_data;
    esp_mqtt_client_handle_t client = event->client;
    static uint8_t error_count = 0;
    switch ((esp_mqtt_event_id_t)event_id) {
        case MQTT_EVENT_CONNECTED:
            ESP_LOGI(TAG_MQTTS, "MQTT_EVENT_CONNECTED");
            flag_connected = true;
            break;

        case MQTT_EVENT_DISCONNECTED:
            ESP_LOGI(TAG_MQTTS, "MQTT_EVENT_DISCONNECTED");
            flag_connected = false;
            esp_mqtt_client_start(client);
            break;

        case MQTT_EVENT_SUBSCRIBED:
            ESP_LOGI(TAG_MQTTS, "MQTT_EVENT_SUBSCRIBED");
            
            break;

        case MQTT_EVENT_PUBLISHED:
            ESP_LOGI(TAG_MQTTS, "MQTT_EVENT_PUBLISHED");
            flag_connected = true;
            break;

        case MQTT_EVENT_DATA:
            ESP_LOGI(TAG_MQTTS, "MQTT_EVENT_DATA");
            printf("TOPIC=%.*s\r\n", event->topic_len, event->topic);
            printf("DATA=%.*s\r\n", event->data_len, event->data);

            flag_connected = true;
            break;

        case MQTT_EVENT_ERROR:
            ESP_LOGI(TAG_MQTTS, "MQTT_EVENT_ERROR");
            error_count++;

            if(error_count > 100){
                //esp_restart();
            }
            break;

        default:
            ESP_LOGI(TAG_MQTTS, "OTHER EVENTS");
            break;
    }   
}

/**
 * @brief Função get para a struct estática mqtt_config_param_t
 * 
 * @param none
 * @return referência da struct estática mqtt_config_param_t
 */
mqtt_config_param_t mqttGetMqttConfigParam(void){
    return mqtt_config_param;
}

/**
 * @brief Função que inicia a conexão com o broker MQTT
 * 
 * @param none
 * @return none
 */
static void mqttAppStart(void){
    const esp_mqtt_client_config_t mqtt_cfg = {
		.broker.address.uri = mqtt_config_param.broker_mqtt_config.broker_uri_mqtt,
		.credentials.username = mqtt_config_param.broker_mqtt_config.broker_user_mqtt,
		.credentials.authentication.password = mqtt_config_param.broker_mqtt_config.broker_password_mqtt,
		.session.last_will.qos = mqtt_config_param.broker_mqtt_config.broker_qos_mqtt,
    };

    memset(&client,0,sizeof(esp_mqtt_client_handle_t));
    client = esp_mqtt_client_init(&mqtt_cfg);
    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, NULL);
    if(client){
        esp_mqtt_client_start(client);
    }
    return;
}

/**
 * @brief Função inicial do componente
 * 
 * @param none
 * @return none
 */
void mqttInit(void){
    ESP_LOGI(TAG_MQTTS, "[APP] Startup..");
    ESP_LOGI(TAG_MQTTS, "[APP] Free memory: %" PRIu32 " bytes", esp_get_free_heap_size());
    ESP_LOGI(TAG_MQTTS, "[APP] IDF version: %s", esp_get_idf_version());

    esp_log_level_set("*", ESP_LOG_INFO);
    esp_log_level_set("mqtt_client", ESP_LOG_VERBOSE);
    esp_log_level_set("MQTT_EXAMPLE", ESP_LOG_VERBOSE);
    esp_log_level_set("TRANSPORT_BASE", ESP_LOG_VERBOSE);
    esp_log_level_set("esp-tls", ESP_LOG_VERBOSE);
    esp_log_level_set("TRANSPORT", ESP_LOG_VERBOSE);
    esp_log_level_set("outbox", ESP_LOG_VERBOSE);

    MQTT_CONFIG_PARAM_DEFAULT(mqtt_config_param);
    
    mqttAppStart();
}
