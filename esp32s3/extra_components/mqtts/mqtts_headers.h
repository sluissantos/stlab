#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "esp_wifi.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "nvs.h"
#include "esp_event.h"
#include "esp_netif.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"

#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"

#include "esp_log.h"
#include "mqtt_client.h"
#include "esp_tls.h"
#include "esp_wifi_types.h"
#include "storage_headers.h"

/**
 * @brief Macro de definição da TAG do componente
 * 
 */
#define TAG_MQTTS "MQTTS"

/**
 * @brief Macro de definição do broker MQTT default
 * 
 */
//#define MQTT_BROKER_URI_DEFAULT         "mqtt://10.158.64.100:1883"
#define MQTT_BROKER_URI_DEFAULT         "mqtt://gwqa.revolog.com.br:1884"
//#define MQTT_BROKER_URI_DEFAULT         "mqtt://192.168.27.70:1883"

/**
 * @brief Macro de definição do user MQTT default
 * 
 */
#define MQTT_BROKER_USERNAME_DEFAULT    "tecnologia"

/**
 * @brief Macro de definição do password MQTT default
 * 
 */
#define MQTT_BROKER_PASSWORD_DEFAULT    "128Parsecs!"

/**
 * @brief Macro de definição do password MQTT default
 * 
 */
#define MQTT_BROKER_KEEP_ALIVE          300

/**
 * @brief Macro de definição do provedor 
 * 
 */
#define MQTT_TOPIC_MANUFACTURER         "lpx"

/**
 * @brief Macro de definição do cliente 
 * 
 */
#define MQTT_TOPIC_PROJECT              "revolog5g"

/**
 * @brief Macro de definição para tópicos de recebimento 
 * 
 */
#define MQTT_DOWNTOPIC                  "down"

/**
 * @brief Macro de definição para tópicos de envio 
 * 
 */
#define MQTT_UPTOPIC                    "up"

/**
 * @brief Macro de definição para tópico genérico 
 * 
 */
#define MQTT_GENERIC                    "generic"


/**
 * @brief Macro usado como flag para retenção das mensagens MQTT 
 * 
 */
#define MQTT_RETAIN_ON                  1

/**
 * @brief Macro usado como flag para não retenção das mensagens MQTT 
 * 
 */
#define MQTT_RETAIN_OFF                 0

/**
 * @brief Macro de definição de QOS 0
 * 
 */
#define MQTT_QOS0                       0

/**
 * @brief Macro de definição de QOS 1
 * 
 */
#define MQTT_QOS1                       1

/**
 * @brief Macro de definição de QOS 2
 * 
 */
#define MQTT_QOS2                       2

/**
 * @brief Macro de definição dos valores DEFAULT da struct mqtt_config_param_t
 * 
 */
#define MQTT_CONFIG_PARAM_DEFAULT(config) do {                                                                                                  \
    strcpy((config).broker_mqtt_config.broker_uri_mqtt, MQTT_BROKER_URI_DEFAULT);                                                               \
    strcpy((config).broker_mqtt_config.broker_user_mqtt, MQTT_BROKER_USERNAME_DEFAULT);                                                         \
    strcpy((config).broker_mqtt_config.broker_password_mqtt, MQTT_BROKER_PASSWORD_DEFAULT);                                                     \
    (config).broker_mqtt_config.broker_keep_alive = MQTT_BROKER_KEEP_ALIVE;                                                              \
    (config).broker_mqtt_config.broker_qos_mqtt = MQTT_QOS1;                                                                                    \
    (config).broker_mqtt_config.broker_retain = MQTT_RETAIN_OFF;                                                                                \
    sprintf((config).topics_mqtt_config.publish_generic, "%s/%s/%s/%s",                                   \
            MQTT_TOPIC_MANUFACTURER, MQTT_TOPIC_PROJECT, MQTT_UPTOPIC, MQTT_GENERIC);                            	\
    sprintf((config).topics_mqtt_config.subscribe_generic, "%s/%s/%s/%s",                                 \
            MQTT_TOPIC_MANUFACTURER, MQTT_TOPIC_PROJECT, MQTT_DOWNTOPIC, MQTT_GENERIC);            				\
} while(0)


typedef struct {

    struct {
        char broker_uri_mqtt[256];                      /*!< Broker MQTT */
        char broker_user_mqtt[256];                     /*!< User MQTT */
        char broker_password_mqtt[256];                 /*!< Password MQTT */
        uint8_t broker_qos_mqtt;                        /*!< QOS MQTT */
        uint8_t broker_retain;                          /*!< Retain MQTT */
        uint16_t broker_keep_alive;                      /*!< Keep Alive MQTT */
    } broker_mqtt_config;

    struct {
        char publish_generic[256];          /*!< Tópico de publicação dos eventos */
        char subscribe_generic[256];      /*!< Tópico de subscrevido para mensagens do display */
    } topics_mqtt_config;
    
} mqtt_config_param_t;

void mqttInit(void);
mqtt_config_param_t mqttGetMqttConfigParam(void);
void mqttPublishMessage(char *message, char *topic);