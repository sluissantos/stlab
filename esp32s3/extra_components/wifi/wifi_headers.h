/**
 * @file wifi_main.c
 * @author Luis Santos (luis.santos@logpyx.com)
 * @brief Componente responsável por realizar a efetica conexão WIFI;
 * 			Variáveis internas;
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

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_wps.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "sdkconfig.h"

#include "lwip/err.h"
#include "lwip/sys.h"

/**
 * @brief Macro de definição da TAG do componente
 * 
 */
#define TAG_WIFI "WIFI"

/**
 * @brief Macro de definição do bit de conexão WIFI
 * 			//1	(1<<0)
 */
#define WIFI_CONNECTED_BIT 						BIT0	

/**
 * @brief Macro de definição do bit de disconexão WIFI
 * 			//2	(1<<1)
 */
#define WIFI_DISCONNECTED_BIT 					BIT1	

/**
 * @brief Macro de definição do estouro do contator de reconexão
 * 			em segundos
 */
#define WIFI_MONITOR_WATCHDOG_CONNECTION_WIFI 	30

/**
 * @brief Macro de definição do estouro do contator de reboot
 * 			em segundos
 */
#define WIFI_MONITOR_WATCHDOG_REBOOT 			10

/**
 * @brief Macro de definição dos valores DEFAULT dos parâmetros WIFI
 * 
 */
#define WIFI_DATA_BASE_DEFAULT(config) do { 	\
    strcpy((config).ssid, "2.4GHZ_REPUBLICA_CEFET"); 	\
    strcpy((config).pwd, "45862425"); 			\
    (config).auth_type = WIFI_AUTH_WPA2_PSK; 	\
} while(0);

typedef struct {

	char ssid[128];     /*!< ssid do roteador WIFI */

	char pwd[128];      /*!< senha do roteador WIFI */

	uint8_t auth_type;  /*!< tipo de autentificação do roteador WIFI */

	uint8_t mac[6];     /*!< endereço mac wifi */
	
} wifi_data_base_t;

void wifiInit(void);
void wifiGetMac(void);
wifi_data_base_t *wifiGetPointerWifiConfig(void);