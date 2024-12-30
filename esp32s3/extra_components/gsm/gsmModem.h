/**
 * @file gsmModem.h
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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "esp_log.h"
#include "esp_err.h"
#include "driver/i2c.h"
#include "driver/gpio.h"
#include "freertos/portmacro.h"
#include "freertos/projdefs.h"
#include "uart_header.h"
#include "esp_timer.h"
#include "sys/time.h"
#include "time.h"

#include "communication.h"
#include "gsmGPS.h"
#include "gsmMQTT.h"
#include "xpowerlib.h"


/**
 * @brief Macro de definição da TAG do componente
 */
#define TAG_MODEM                                       "MODEM" 

/**
 * @brief Macro da flag do log dos comandos AT enviados. Comente caso não queira que sejam exibidos
 */
#define GSM_MODEM_LOG_MODEM_SEND

/**
 * @brief Macro da flag do log dos comandos AT lidos. Comente caso não queira que sejam exibidos
 */
#define GSM_MODEM_LOG_MODEM_READ

/**
 * @brief Macro que define a quantidade de tentativas de leitura das respostas do modem
 */
#define GSM_MODEM_RETRY_READ_UART                       5

/**
 * @brief Macro que define a quantidade de tentativas de escritas uart no modem
 */
#define GSM_MODEM_RETRY_SEND_UART                       5

/**
 * @brief Macro que define o pino PWR
 */
#define GSM_MODEM_PWR_PIN                               (41)

/**
 * @brief Macro que define o pino DTR
 */
#define GSM_MODEM_DTR_PIN                               (42)

/**
 * @brief Macro que define o pino RI
 */
#define GSM_MODEM_RI_PIN                                (3)

/**
 * @brief Macro de definição de string usado para verificar se o comando recebido está OK
 */
#define GSM_MODEM_OK                                    "OK"

/**
 * @brief Macro de definição de string usado para verificar se o comando recebido deu ERROR
 */
#define GSM_MODEM_ERROR                                 "ERROR"

/**
 * @brief Macro de definição de string usado para verificar se o comando recebido deu READY
 */
#define GSM_MODEM_READY                                 "READY"

/**
 * @brief Macro de definição de string carriege return and line feed
 */
#define GSM_MODEM_NL                                    "\r\n"

/**
 * @brief Macro de definição de string usada como sinal para envio da mensagem MQTT
 */
#define GSM_MODEM_SIGNAL                                ">"

/**
 * @brief Macro de definição de string do prefixo AT
 */
#define GMS_MODEM_AT                                    "AT"

/**
 * @brief Macro das configurações do PDP context
 */
#define GMS_MODEM_DEFINE_PDP_CONTEXT                    "0,1,\"smart.m2m.vivo.com.br\""

/**
 * @brief Macro dos parâmetros do servidor NTP
 */
#define GMS_MODEM_DEFINE_NTP_PARAM                      "\"200.186.125.195\",-12,1,2"

/**
 * @brief Macro de definição do padrão esperado para o comado AT+CEREG
 */
#define GSM_MODEM_REGISTRATION_STATUS_XREG_OK_HOME      "+CEREG: 0,1"

/**
 * @brief Macro de definição do padrão esperado para o comado AT+CGREG
 */
#define GSM_MODEM_REGISTRATION_STATUS_XREG_OK_ROAMING   "+CGREG: 0,5"

/**
 * @brief Macro de definição para flag de conexão do GPRS
 */
#define GSM_MODEM_GPRS_CONNECTED                        "+CGATT: 1"

/**
 * @brief Macro de definição da flag de error no retorno do comando
 */
#define GSM_MODEM_NO_EXPECTED_ANSWER                    0

/**
 * @brief Macro de definição da flag de que o retorno obtido foi o retorno esperado
 */
#define GSM_MODEM_EXPECTED_ANSWER                       1

/**
 * @brief Macro de definição da flag de sem retorno do comando
 */
#define GSM_MODEM_NO_ANSWER                             2

/**
 * @brief Macro de definição de não obtenção do IP
 */
#define GSM_MODEM_IP_ADDRESS_NO_OBTAINED                0

/**
 * @brief Macro de definição de obtenção do IP
 */
#define GSM_MODEM_IP_ADDRESS_OBTAINED                   1

/**
 * @brief Macro de definição do tempo padrão para envio das informações do modulo, em milisegundos
 */
#define GMS_MODEM_PUBLISH_INFO_TIME                     60000

/**
 * @brief Macro de definição para os valores padrão da struct do componente
 */
#define GSM_MODEM_CONFIG_DEFAULT(config) do {                                   \
    (config).gsm_modem_network_mode     = GSM_MODEM_NETWORK_MODE_GSM_LTE_ONLY;  \
    (config).gsm_modem_preferred_mode   = GSM_MODEM_PREFERRED_MODE_CATM;        \
    strcpy((config).gsm_modem_ip, "");                                          \
    strcpy((config).gsm_modem_imei, "");                                        \
    (config).gsm_modem_signal           = 0;                                    \
} while(0);

/**
 * @brief Macro de definição da struct do componente
 */
typedef struct{
    uint8_t gsm_modem_network_mode;         /*!< Network mode */
    uint8_t gsm_modem_preferred_mode;       /*!< Preferred mode */
    char    gsm_modem_ip[32];               /*!< IP */
    char    gsm_modem_imei[32];             /*!< IMEI module */
    uint8_t  gsm_modem_signal;              /*!< RSSI signal */
}gsm_modem_config_t;

/**
 * @brief Macro de definição para os valores de network mode
 */
typedef enum{
    GSM_MODEM_NETWORK_MODE_AUTOMATIC    = 2,
    GSM_MODEM_NETWORK_MODE_GSM_ONLY     = 13,
    GSM_MODEM_NETWORK_MODE_LTE_ONLY     = 38,
    GSM_MODEM_NETWORK_MODE_GSM_LTE_ONLY = 51,
}gsm_modem_network_mode_enum;

/**
 * @brief Macro de definição para os valores de preferred mode
 */
typedef enum {
    GSM_MODEM_PREFERRED_MODE_CATM = 1,
    GSM_MODEM_PREFERRED_MODE_NBIOT,
    GSM_MODEM_PREFERRED_MODE_CAT1_NBIOT,
}gsm_modem_preferred_mode_enum;

void gsmModemStart(void);
void gsmModemInit(void);
void gsmModemSendData(char *data);
bool gsmModemWaitResponse(uint8_t *modemAnswer);
uint8_t gsmModemCommand(char *data, uint8_t *answer, const char *answer_expected);
gsm_modem_config_t *gsmModemGetPointerConfig(void);
gsm_modem_config_t gsmModemGetConfig(void);
void gsmModemGetValue(const char *answer, int position, double *value);
void gsmModemNetworkTask(void * pvParameter);
void gsmModemRestartModem(void);
void gsmModemPdpContext(void);
void gsmModemSetNetworkMode(uint8_t mode);
void gsmModemSetPreferredMode(uint8_t mode);
void gsmModemGetRegistrationStatus(void);
bool gsmModemGprsConnect(void);
bool gsmModemAppNetworkActive(void);
void gsmGpsHotGps(void);
