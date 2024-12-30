/**
 * @file communication.h
 * @author Luis Santos (luis.santos@logpyx.com)
 * @author Henrique Ferreira (henrique.ferreira@logpyx.com)
 * @brief Esse arquivo apresenta as funções para gravação e leitura dos buffers BLE e Display; 
 *          FUnções de empacotamento de pacotes e desempacotamentos de pacotes recebidos via BLE/UART/MQTT;
 *              Variáveis internas;
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
#include "uart_header.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "cJSON.h"
#include "nvs.h"
#include "nvs_flash.h"
#include "devices_headers.h"
#include "uart_header.h"
#include "mqtts_headers.h"
#include "gsmModem.h"

/**
 * @brief Macro de definição da TAG do componente
 * 
 */
#define TAG_COMM                            "COMM"

/**
 * @brief Macro de definição da interface BLE
 * 
 */
#define COMM_INTERFACE_UART                 0

/**
 * @brief Macro de definição de retorno de logs da placa
 * 
 */
#define DUMMY_RESPONSE                      1

/**
 * @brief Macro de definição do tamanho do buffer BLE
 * 
 */
#define COMM_BUFFER_UART_SIZE                100

/**
 * @brief Macro usado para definição do byte inicial do pacote BLE
 * 
 */
#define STX                                 0x02

/**
 * @brief Macro usado para definição do byte final do pacote BLE
 * 
 */
#define RTX                                 0x03

/**
 * @brief Macro usado para definição do opcode generico de distancia
 * 
 */
#define WR_GENERIC_DISTANCE_OPCODE          0xAB

/**
 * @brief Macro usado para definição do opcode generico
 * 
 */
#define WR_GENERIC_OPCODE                   0xCF

typedef struct {   

    uint8_t maxlen;							                        /*!< Comprimento máximo que o buffer pode ocupar */

    uint8_t size;							                        /*!< Tamanho do buffer */

    uint8_t head;							                        /*!< Head do buffer circular */

    uint8_t tail;							                        /*!< Tail do buffer circular */

    uint8_t bufferUart[COMM_BUFFER_UART_SIZE];		                /*!< Componente da estrutura */

} buffer_t;

typedef enum {
    START_BUFFER=0,  	/*!< Estado para iniciar a formatação dos dados */

    BUFFER_SIZE,	 	/*!< Estado de validação do tamanho do buffer que será entrege */

    FILLING_IN,			/*!< Estado para armazenar as informações recebidas */

    CHECK_SUM,			/*!< Estado de validação dos dados coletados */

    END_BUFFER			/*!< Estado para concluir o processo de montagem */

} buffer_states_t;

int8_t commBufferPop(buffer_t * buffer, void *var);
void commDowngradeBufferUART(void);
void commUpdateBufferTask(void * pvParameter);
