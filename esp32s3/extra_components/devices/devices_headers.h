/**
 * @file devices_headers.c
 * @author Luis Santos (luis.santos@logpyx.com)
 * @author Henrique Ferreira (henrique.ferreira@logpyx.com)
 * @brief Trata funções relacionadas aos devices (periféricos), gerenciamento de conexão,configuração e informações sobre;
 *          Variáveis internas;  
 * 
 * @version 2.0.0
 * @date 2024-03
 * 
 * @attention
 * 
 * <h2><center>&copy; COPYRIGHT 2023 LogPyx S/A</center></h2>
 * 
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "communication.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_bt.h"
#include "esp_gap_ble_api.h"
#include "esp_gatts_api.h"
#include "esp_bt_defs.h"
#include "esp_bt_main.h"
#include "esp_gatt_common_api.h"
#include "sdkconfig.h"
#include "storage_headers.h"
#include "esp_heap_caps.h"
#include "esp_heap_task_info.h"

/**
 * @brief Macro de definição da TAG do componente
 * 
 */
#define TAG_DEVICE "DEVICE"

#define DEVICE_QNT          4                       // Quantidade de dispositivos 
#define DEVICE_TASK_DELAY   500
#define DEVICE_BLE1_INDX    0                       // Indice para gerenciar dispositivo conectado BLE
#define DEVICE_BLE2_INDX    1                       // Indice para gerenciar dispositivo conectado BLE
#define DEVICE_BLE3_INDX    2                       // Indice para gerenciar dispositivo conectado BLE
#define DEVICE_BLE4_INDX    3
#define DEVICE_UART_INDX    4                       // Indice para gerenciar dispositivo conectado a uart


#define DEVICE_STATUS_CONNECTING                        1
#define DEVICE_STATUS_WAIT_FOR_CONECTING                2
#define DEVICE_STATUS_CONNECTED                         3

#define DEVICE_TIMEOUT_LIMITE                           3 // 10 * 500ms = 5s

/**
 * @brief Macro de definição do identificador do display esquerdo
 * 
 */
#define DEVICE_DISPLAY_IDENTIFICATION_LEFT              0

/**
 * @brief Macro de definição do identificador do display central
 * 
 */
#define DEVICE_DISPLAY_IDENTIFICATION_CENTRAL           1

/**
 * @brief Macro de definição do identificador do display direito
 * 
 */
#define DEVICE_DISPLAY_IDENTIFICATION_RIGHT             2

/**
 * @brief Macro de definição do identificador da orientação esquerda
 * 
 */
#define DEVICE_DISPLAY_DIRECTION_LEFT                   0

/**
 * @brief Macro de definição do identificador da orientação direita
 * 
 */
#define DEVICE_DISPLAY_DIRECTION_RIGHT                  1

/**
 * @brief Macro de definição do estado de não limpar placa
 * 
 */
#define DEVICE_DISPLAY_NO_ERASE                         0

/**
 * @brief Macro de definição do estado de limpar placa
 * 
 */
#define DEVICE_DISPLAY_ERASE                            1

/**
 * @brief Macro de definição para não mostrar logs no display
 * 
 */
#define DEVICE_DISPLAY_NO_SHOW_LOG                      0

/**
 * @brief Macro de definição para mostrar logs no display
 * 
 */
#define DEVICE_DISPLAY_SHOW_LOG                         1

/**
 * @brief Macro de definição do tempo até o estado OFFLINE, em segundos
 * 
 */
#define DEVICE_OFFLINE_TIME_DEFAULT                     180

/**
 * @brief Macro de definição do evento de restart após o estado OFFLINE
 * 
 */
#define DEVICE_EVENT_RESTART                            0

/**
 * @brief Macro de definição do evento de estado OFFLINE
 * 
 */
#define DEVICE_EVENT_OFFLINE                            1

/**
 * @brief Macro de definição do evento de disconexão com o broker mqtt
 * 
 */
#define DEVICE_EVENT_MQTT_DISCONNECT                    2

/**
 * @brief Macro de definição do evento do evento DEFAULT da conexão MQTT
 * 
 */
#define DEVICE_EVENT_MQTT_DEFAULT                       3

/**
 * @brief Macro de definição do evento do evento ERRO TYPE NONE da conexão MQTT
 * 
 */
#define DEVICE_EVENT_MQTT_ERROR_TYPE_NONE               4

/**
 * @brief Macro de definição do evento do evento ERRO TCP TRANSPORT da conexão MQTT
 * 
 */
#define DEVICE_EVENT_MQTT_ERROR_TYPE_TCP_TRANSPORT      5

/**
 * @brief Macro de definição do evento do evento ERRO CONECTION REFUSED da conexão MQTT
 * 
 */
#define DEVICE_EVENT_MQTT_ERROR_TYPE_CONNECTION_REFUSED 7

/**
 * @brief Macro de definição da versão major do firmware
 * 
 */
#define DEVICE_VERSION_MAJOR                            2

/**
 * @brief Macro de definição da versão minor do firmware
 * 
 */
#define DEVICE_VERSION_MINOR                            0

/**
 * @brief Macro de definição dos valores padrão da struct device_t
 * 
 */
#define DEVICE_DEFAULT() {                              \
    .interface =1, /*COMM_INTERFACE_BLE_SERVER*/        \
    .deviceName="",                                     \
    .gattsConnectionID = -1,                            \
    .isConnected = 0,                                   \
    .channel = 0,                                       \
    .status =DEVICE_STATUS_WAIT_FOR_CONECTING,          \
    .timeout = 0,                                       \
    .dataReady = 0,                                     \
    .connID = 0xFFFF,                                   \
}

typedef struct{
    uint8_t interface;
    char deviceName[20];
    int16_t gattsConnectionID;
    uint8_t channel;
    uint8_t isConnected;
    uint8_t status;
    uint8_t timeout;
    uint8_t dataReady;
    uint16_t connID;
} device_t;

////////////////////////////////////////////////////////////////////////////////////
//Functions
////////////////////////////////////////////////////////////////////////////////////
void deviceInit(void);
void deviceConnectionTask(void * pvParameter);
int8_t deviceConnect(uint8_t newDeviceIndx);
int8_t deviceDisconnect(uint8_t deviceIndx);
device_t *deviceGet(uint8_t deviceIndx);
device_t * deviceGetCelular();
void deviceSetIndxCelular(int8_t index);
uint8_t deviceGetIndxCelular();
void deviceRotinaLed();