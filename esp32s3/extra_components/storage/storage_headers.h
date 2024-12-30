/**
 * @file storage_headers.h
 * @author Luis Santos (luis.santos@logpyx.com)
 * @author Luis Henrique Maciel (luis@logpyx.com)
 * @author Henrique Ferreira (henrique.ferreira@logpyx.com)
 * @brief Esse arquivo apresenta as funções para leitura e escrita nas partições de armazenamento
 * para realizar tanto a configuração geral do Aura quanto das variáveis internas.  
 * 
 * @version 2.0.0
 * @date 2024-04
 * 
 * @attention
 * 
 * <h2><center>&copy; COPYRIGHT 2023 LogPyx S/A</center></h2>
 * 
 */

#ifndef STORAGE_HEADERS_H
#define STORAGE_HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nvs_flash.h"
#include "devices_headers.h"

/**
 * @brief Macro de definição da TAG do componente
 * 
 */
#define TAG_STORAGE                                             "STORAGE"

/**
 * @brief Configuração para partição NVS (Non-volatile Storage) do ESP
 * 
 */
#define NVS_STORAGE_PARTITION                                   "nvs"

/**
 * @brief Macro de definição do label da nvs para struct usada como configuração da conexão mqtt
 * 
 */
#define STORAGE_MQTT_CONFIG_PARAM                               "MQTT_CONFIG"

/**
 * @brief Macro de definição do label da nvs para struct usada pro sub-componente gsmGps
 * 
 */
#define STORAGE_GSM_GPS_PARAM                                   "GSM_GPS"

/**
 * @brief Macro de definição do label da nvs para struct usada como configuração OTA
 * 
 */
#define STORAGE_OTA_FIRMWARE_UPDATE                             "OTA_FW_UPDATE"

/**
 * @brief Macro de definição do label da nvs para armazenamento do certificado OTA
 * 
 */
#define STORAGE_OTA_FIRMWARE_UPDATE_CERT                        "OTA_FW_UP_CERT"

void storageInit(void);
void storageGetString(char* nvs_key, char* data);
void storageSetString(char* nvs_key, char* data);
void storageGetUint8(char* nvs_key, uint8_t* int_data);
void storageSetUint8(char* nvs_key, uint8_t* int_data);
void storageGetUint16(char* nvs_key, uint16_t* int_data);
void storageSetUint16(char* nvs_key, uint16_t* int_data);
void storageGetUint32(char* nvs_key, uint32_t* int_data);
void storageSetUint32(char* nvs_key, uint32_t* int_data);
esp_err_t storageGetBlob(const char *nvs_key, void *data, size_t *size);
esp_err_t storageSetBlob(const char *nvs_key, const void *data, size_t size);

#endif
