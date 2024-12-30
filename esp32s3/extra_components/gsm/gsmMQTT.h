/**
 * @file gsmMQTT.H
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

#pragma once

#include "gsmModem.h"

/**
 * @brief Macro de definição da TAG do componente
 */
#define TAG_MQTT                                    "MQTT" 

/**
 * @brief Macro de definição do broker MQTT default
 */
#define GSM_MQTT_BROKER_URL_DEFAULT                 "gw.qa.revolog.com.br"

/**
 * @brief Macro de definição da porta MQTT default
 */
#define GSM_MQTT_BROKER_PORT_DEFAULT                1883

/**
 * @brief Macro de definição do user MQTT default
 */
#define GSM_MQTT_BROKER_USERNAME_DEFAULT            "tecnologia"

/**
 * @brief Macro de definição do password MQTT default
 */
#define GSM_MQTT_BROKER_PASSWORD_DEFAULT            "128Parsecs!"

/**
 * @brief Macro de definição do provedor 
 */
#define GSM_MQTT_TOPIC_MANUFACTURER                 "stlab"

/**
 * @brief Macro de definição do produto
 */
#define GSM_MQTT_TOPIC_PROJECT                      "sim7080"

/**
 * @brief Macro de definição do cliente
 */
#define GSM_MQTT_TOPIC_CLIENT                       "lpx"

/**
 * @brief Macro de definição para tópicos de recebimento 
 */
#define GSM_MQTT_TOPIC_DOWN                         "down"

/**
 * @brief Macro de definição para tópicos de envio 
 */
#define GSM_MQTT_TOPIC_UP                           "up"

/**
 * @brief Macro de definição para tópico status
 */
#define GSM_MQTT_TOPIC_STATUS                       "status"

/**
 * @brief Macro de definição para tópico genérico 
 */
#define GSM_MQTT_TOPIC_GENERIC                      "generic"

/**
 * @brief Macro de definição para tópico genérico 
 */
#define GSM_MQTT_TOPIC_INFO                        "info"

/**
 * @brief Macro de definição para tópico GPS
 */
#define GSM_MQTT_TOPIC_GPS                          "gps"

/**
 * @brief Macro usado como flag para retenção das mensagens MQTT 
 */
#define GSM_MQTT_KEEPALIVE                          100

/**
 * @brief Resume communication based on persent session
 */
#define GSM_MQTT_CLEAN_SESSION                      0

/**
 * @brief Macro de definição de QOS 0
 */
#define GSM_MQTT_QOS0                               0

/**
 * @brief Macro de definição de QOS 1
 */
#define GSM_MQTT_QOS1                               1

/**
 * @brief Macro de definição de QOS 2
 */
#define GSM_MQTT_QOS2                               2

/**
 * @brief Macro usado como flag para não retenção das mensagens MQTT 
 */
#define GSM_MQTT_RETAIN                             0

/**
 * @brief Macro de definição de obtenção do IP
 */
#define GSM_MQTT_CONNECTION_ON                      "+SMSTATE: 1"

/**
 * @brief Macro de definição de obtenção do IP
 */
#define GSM_MQTT_CONNECTION_ON_PRESENT              "+SMSTATE: 2"

/**
 * @brief Macro de definição da quantidade de tentativas de conexão com o broker
 */
#define GSM_MQTT_MAX_MQTT_CONNECTION_RETRY          5

/**
 * @brief Macro de definição para os valores padrão da struct do componente
 */
#define GSM_MQTT_CONFIG_PARAM_DEFAULT(config, IMEI) do {                                                                                    \
    strcpy((config).broker_mqtt_config.broker_url_mqtt, GSM_MQTT_BROKER_URL_DEFAULT);                                                       \
    (config).broker_mqtt_config.broker_port_mqtt = GSM_MQTT_BROKER_PORT_DEFAULT;                                                            \
    strcpy((config).broker_mqtt_config.broker_user_mqtt, GSM_MQTT_BROKER_USERNAME_DEFAULT);                                                 \
    strcpy((config).broker_mqtt_config.broker_password_mqtt, GSM_MQTT_BROKER_PASSWORD_DEFAULT);                                             \
    (config).broker_mqtt_config.broker_clean_session = GSM_MQTT_CLEAN_SESSION;                                                              \
    (config).broker_mqtt_config.broker_qos_mqtt = GSM_MQTT_QOS1;                                                                            \
    (config).broker_mqtt_config.broker_retain = GSM_MQTT_RETAIN;                                                                            \
    (config).broker_mqtt_config.broker_keepalive_mqtt = GSM_MQTT_KEEPALIVE;                                                                 \
    sprintf((config).topics_mqtt_config.publish_status, "%s/%s/%s/%s",                                                                      \
            GSM_MQTT_TOPIC_MANUFACTURER, GSM_MQTT_TOPIC_PROJECT, GSM_MQTT_TOPIC_UP, GSM_MQTT_TOPIC_STATUS);                                 \
    sprintf((config).topics_mqtt_config.publish_gps, "%s/%s/%s/%s/%s/%s",                                                                   \
            GSM_MQTT_TOPIC_MANUFACTURER, GSM_MQTT_TOPIC_PROJECT, GSM_MQTT_TOPIC_CLIENT, IMEI, GSM_MQTT_TOPIC_UP, GSM_MQTT_TOPIC_GPS);       \
    sprintf((config).topics_mqtt_config.publish_info, "%s/%s/%s/%s/%s/%s",                                                                  \
            GSM_MQTT_TOPIC_MANUFACTURER, GSM_MQTT_TOPIC_PROJECT, GSM_MQTT_TOPIC_CLIENT, IMEI, GSM_MQTT_TOPIC_UP, GSM_MQTT_TOPIC_INFO);      \
    sprintf((config).topics_mqtt_config.subscribe_generic, "%s/%s/%s/%s/%s/%s",                                                             \
            GSM_MQTT_TOPIC_MANUFACTURER, GSM_MQTT_TOPIC_PROJECT, GSM_MQTT_TOPIC_CLIENT, IMEI, GSM_MQTT_TOPIC_DOWN, GSM_MQTT_TOPIC_GENERIC); \
} while(0);

/**
 * @brief Macro de definição da struct do componente
 */
typedef struct {
    struct {
        char broker_url_mqtt[32];                      /*!< Broker MQTT */
        uint16_t broker_port_mqtt;                     /*!< Broker port MQTT */
        char broker_user_mqtt[32];                     /*!< User MQTT */
        char broker_password_mqtt[32];                 /*!< Password MQTT */
        uint8_t broker_clean_session;                  /*!< Broker session clean */
        uint8_t broker_qos_mqtt;                       /*!< QOS MQTT */
        uint8_t broker_retain;                         /*!< Retain MQTT */
        uint16_t broker_keepalive_mqtt;                /*!< Broker keepalive MQTT */
    } broker_mqtt_config;

    struct {
        char publish_status[128];                       /*!< Tópico de publicação dos eventos de status*/
        char publish_generic[128];                      /*!< Tópico de publicação dos eventos */
        char publish_gps[128];                          /*!< Tópico de publicação do gps do modem */
        char publish_info[128];                         /*!< Tópico de publicação dos status do modem */
        char subscribe_generic[128];                    /*!< Tópico de subscrevido para mensagens do display */
    } topics_mqtt_config;
    
} gsm_mqtt_config_param_t;

bool gsmMqttPublishMqtt(char *message, char *topic);
void gsmMqttInit(void);
gsm_mqtt_config_param_t gsmMqttGetMqttConfigParam(void);
bool gsmMqttVerifyIP(uint8_t *answer);
bool gsmMqttConnect(void);
void gsmMqttDisconnect(void);
gsm_mqtt_config_param_t gsmMqttGetMqttConfigParam(void);