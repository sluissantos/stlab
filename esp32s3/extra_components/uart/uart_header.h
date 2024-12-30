#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "driver/uart.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "sdkconfig.h"

#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"

#include "sdkconfig.h"
#include "esp_log.h"

#define TAG_UART "UART"


#define UART0_INSTANCE      0
#define UART0_PIN_RX        44 
#define UART0_PIN_TX        43
#define UART0_BAUD_RATE     115200

#define UART1_INSTANCE      1
#define UART1_PIN_RX        4 
#define UART1_PIN_TX        5
#define UART1_BAUD_RATE     115200

#define UART_BUFFER_SIZE    1024

#define UART0_CONFIG_DEFAULT() {            \
    .baud_rate = UART0_BAUD_RATE,          \
    .data_bits = UART_DATA_8_BITS,         \
    .parity    = UART_PARITY_DISABLE,      \
    .stop_bits = UART_STOP_BITS_1,         \
    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE, \
    .source_clk = UART_SCLK_APB,           \
}

#define UART1_CONFIG_DEFAULT() {            \
    .baud_rate = UART1_BAUD_RATE,          \
    .data_bits = UART_DATA_8_BITS,         \
    .parity    = UART_PARITY_DISABLE,      \
    .stop_bits = UART_STOP_BITS_1,         \
    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE, \
    .source_clk = UART_SCLK_APB,           \
}

void uartInit(void);
uint8_t uartSendData(uint8_t uartInstace, char *data, uint8_t length);
uint8_t uartReadData(uint8_t uartInstace, uint8_t *data);
void uartTask(void * pvParameter);
size_t uartAvailable();
void uartFlush();