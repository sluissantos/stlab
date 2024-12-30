/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "uart_header.h"
#include "devices_headers.h"
#include "storage_headers.h"
#include "mqtts_headers.h"
#include "wifi_headers.h"
#include "xpowerlib.h"
#include "gsmModem.h"

TaskHandle_t commBufferTask_handler;
TaskHandle_t gsmModemGpsNetworkTask_handler;

void app_main(void){
    storageInit();

    xpowerInit();
    
    uartInit();

    xTaskCreatePinnedToCore(commUpdateBufferTask,"COMM_BUFFER_TASK",(1024 * 10),NULL,0,&commBufferTask_handler,0);

    gsmModemStart();

    gsmModemInit();

    gsmMqttInit();

    xTaskCreatePinnedToCore(gsmModemNetworkTask,"GSM_MODEM_TASK",(1024 * 20),NULL,0,&gsmModemGpsNetworkTask_handler,0);
}
