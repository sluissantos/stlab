# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# compile ASM with /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc
# compile C with /home/santos/esp5.1.2/.espressif/tools/xtensa-esp32s3-elf/esp-12.2.0_20230208/xtensa-esp32s3-elf/bin/xtensa-esp32s3-elf-gcc
ASM_DEFINES = -DMBEDTLS_CONFIG_FILE=\"mbedtls/esp_config.h\" -DSOC_MMU_PAGE_SIZE=CONFIG_MMU_PAGE_SIZE -DUNITY_INCLUDE_CONFIG_H

ASM_INCLUDES = -I/home/santos/esp/v5.1.2/esp-idf/components/xtensa/include -I/home/santos/esp/v5.1.2/esp-idf/components/xtensa/esp32s3/include -I/home/santos/Documents/stlab/esp32s3/build/config -I/home/santos/esp/v5.1.2/esp-idf/components/newlib/platform_include -I/home/santos/esp/v5.1.2/esp-idf/components/freertos/FreeRTOS-Kernel/include -I/home/santos/esp/v5.1.2/esp-idf/components/freertos/FreeRTOS-Kernel/portable/xtensa/include -I/home/santos/esp/v5.1.2/esp-idf/components/freertos/esp_additions/include/freertos -I/home/santos/esp/v5.1.2/esp-idf/components/freertos/esp_additions/include -I/home/santos/esp/v5.1.2/esp-idf/components/freertos/esp_additions/arch/xtensa/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_hw_support/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_hw_support/include/soc -I/home/santos/esp/v5.1.2/esp-idf/components/esp_hw_support/include/soc/esp32s3 -I/home/santos/esp/v5.1.2/esp-idf/components/esp_hw_support/port/esp32s3/. -I/home/santos/esp/v5.1.2/esp-idf/components/esp_hw_support/port/esp32s3/private_include -I/home/santos/esp/v5.1.2/esp-idf/components/heap/include -I/home/santos/esp/v5.1.2/esp-idf/components/log/include -I/home/santos/esp/v5.1.2/esp-idf/components/soc/include -I/home/santos/esp/v5.1.2/esp-idf/components/soc/esp32s3 -I/home/santos/esp/v5.1.2/esp-idf/components/soc/esp32s3/include -I/home/santos/esp/v5.1.2/esp-idf/components/hal/esp32s3/include -I/home/santos/esp/v5.1.2/esp-idf/components/hal/include -I/home/santos/esp/v5.1.2/esp-idf/components/hal/platform_port/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_rom/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_rom/include/esp32s3 -I/home/santos/esp/v5.1.2/esp-idf/components/esp_rom/esp32s3 -I/home/santos/esp/v5.1.2/esp-idf/components/esp_common/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_system/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_system/port/soc -I/home/santos/esp/v5.1.2/esp-idf/components/esp_system/port/include/private -I/home/santos/esp/v5.1.2/esp-idf/components/lwip/include -I/home/santos/esp/v5.1.2/esp-idf/components/lwip/include/apps -I/home/santos/esp/v5.1.2/esp-idf/components/lwip/include/apps/sntp -I/home/santos/esp/v5.1.2/esp-idf/components/lwip/lwip/src/include -I/home/santos/esp/v5.1.2/esp-idf/components/lwip/port/include -I/home/santos/esp/v5.1.2/esp-idf/components/lwip/port/freertos/include -I/home/santos/esp/v5.1.2/esp-idf/components/lwip/port/esp32xx/include -I/home/santos/esp/v5.1.2/esp-idf/components/lwip/port/esp32xx/include/arch -I/home/santos/esp/v5.1.2/esp-idf/components/esp_ringbuf/include -I/home/santos/esp/v5.1.2/esp-idf/components/efuse/include -I/home/santos/esp/v5.1.2/esp-idf/components/efuse/esp32s3/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/deprecated -I/home/santos/esp/v5.1.2/esp-idf/components/driver/analog_comparator/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/dac/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/gpio/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/gptimer/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/i2c/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/i2s/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/ledc/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/mcpwm/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/parlio/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/pcnt/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/rmt/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/sdio_slave/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/sdmmc/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/sigma_delta/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/spi/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/temperature_sensor/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/touch_sensor/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/twai/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/uart/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/usb_serial_jtag/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/touch_sensor/esp32s3/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_pm/include -I/home/santos/esp/v5.1.2/esp-idf/components/mbedtls/port/include -I/home/santos/esp/v5.1.2/esp-idf/components/mbedtls/mbedtls/include -I/home/santos/esp/v5.1.2/esp-idf/components/mbedtls/mbedtls/library -I/home/santos/esp/v5.1.2/esp-idf/components/mbedtls/esp_crt_bundle/include -I/home/santos/esp/v5.1.2/esp-idf/components/mbedtls/mbedtls/3rdparty/everest/include -I/home/santos/esp/v5.1.2/esp-idf/components/mbedtls/mbedtls/3rdparty/p256-m -I/home/santos/esp/v5.1.2/esp-idf/components/mbedtls/mbedtls/3rdparty/p256-m/p256-m -I/home/santos/esp/v5.1.2/esp-idf/components/esp_app_format/include -I/home/santos/esp/v5.1.2/esp-idf/components/bootloader_support/include -I/home/santos/esp/v5.1.2/esp-idf/components/bootloader_support/bootloader_flash/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_partition/include -I/home/santos/esp/v5.1.2/esp-idf/components/app_update/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_mm/include -I/home/santos/esp/v5.1.2/esp-idf/components/spi_flash/include -I/home/santos/esp/v5.1.2/esp-idf/components/pthread/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_timer/include -I/home/santos/esp/v5.1.2/esp-idf/components/app_trace/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_event/include -I/home/santos/esp/v5.1.2/esp-idf/components/nvs_flash/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_phy/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_phy/esp32s3/include -I/home/santos/esp/v5.1.2/esp-idf/components/vfs/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_netif/include -I/home/santos/esp/v5.1.2/esp-idf/components/wpa_supplicant/include -I/home/santos/esp/v5.1.2/esp-idf/components/wpa_supplicant/port/include -I/home/santos/esp/v5.1.2/esp-idf/components/wpa_supplicant/esp_supplicant/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_coex/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/wifi_apps/include -I/home/santos/esp/v5.1.2/esp-idf/components/bt/include/esp32c3/include -I/home/santos/esp/v5.1.2/esp-idf/components/bt/common/osi/include -I/home/santos/esp/v5.1.2/esp-idf/components/bt/common/api/include/api -I/home/santos/esp/v5.1.2/esp-idf/components/bt/common/btc/profile/esp/blufi/include -I/home/santos/esp/v5.1.2/esp-idf/components/bt/common/btc/profile/esp/include -I/home/santos/esp/v5.1.2/esp-idf/components/bt/host/bluedroid/api/include/api -I/home/santos/esp/v5.1.2/esp-idf/components/bt/porting/ext/tinycrypt/include -I/home/santos/esp/v5.1.2/esp-idf/components/unity/include -I/home/santos/esp/v5.1.2/esp-idf/components/unity/unity/src -I/home/santos/esp/v5.1.2/esp-idf/components/cmock/CMock/src -I/home/santos/esp/v5.1.2/esp-idf/components/console -I/home/santos/esp/v5.1.2/esp-idf/components/http_parser -I/home/santos/esp/v5.1.2/esp-idf/components/esp-tls -I/home/santos/esp/v5.1.2/esp-idf/components/esp-tls/esp-tls-crypto -I/home/santos/esp/v5.1.2/esp-idf/components/esp_adc/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_adc/interface -I/home/santos/esp/v5.1.2/esp-idf/components/esp_adc/esp32s3/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_adc/deprecated/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_gdbstub/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_hid/include -I/home/santos/esp/v5.1.2/esp-idf/components/tcp_transport/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_http_client/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_http_server/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_https_ota/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_psram/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_lcd/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_lcd/interface -I/home/santos/esp/v5.1.2/esp-idf/components/protobuf-c/protobuf-c -I/home/santos/esp/v5.1.2/esp-idf/components/protocomm/include/common -I/home/santos/esp/v5.1.2/esp-idf/components/protocomm/include/security -I/home/santos/esp/v5.1.2/esp-idf/components/protocomm/include/transports -I/home/santos/esp/v5.1.2/esp-idf/components/esp_local_ctrl/include -I/home/santos/esp/v5.1.2/esp-idf/components/espcoredump/include -I/home/santos/esp/v5.1.2/esp-idf/components/espcoredump/include/port/xtensa -I/home/santos/esp/v5.1.2/esp-idf/components/wear_levelling/include -I/home/santos/esp/v5.1.2/esp-idf/components/sdmmc/include -I/home/santos/esp/v5.1.2/esp-idf/components/fatfs/diskio -I/home/santos/esp/v5.1.2/esp-idf/components/fatfs/vfs -I/home/santos/esp/v5.1.2/esp-idf/components/fatfs/src -I/home/santos/esp/v5.1.2/esp-idf/components/idf_test/include -I/home/santos/esp/v5.1.2/esp-idf/components/idf_test/include/esp32s3 -I/home/santos/esp/v5.1.2/esp-idf/components/ieee802154/include -I/home/santos/esp/v5.1.2/esp-idf/components/json/cJSON -I/home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/include -I/home/santos/esp/v5.1.2/esp-idf/components/perfmon/include -I/home/santos/esp/v5.1.2/esp-idf/components/spiffs/include -I/home/santos/esp/v5.1.2/esp-idf/components/touch_element/include -I/home/santos/esp/v5.1.2/esp-idf/components/ulp/ulp_common/include -I/home/santos/esp/v5.1.2/esp-idf/components/ulp/ulp_common/include/esp32s3 -I/home/santos/esp/v5.1.2/esp-idf/components/usb/include -I/home/santos/esp/v5.1.2/esp-idf/components/wifi_provisioning/include -I/home/santos/Documents/stlab/esp32s3/extra_components/uart -I/home/santos/Documents/stlab/esp32s3/extra_components/storage -I/home/santos/Documents/stlab/esp32s3/extra_components/devices -I/home/santos/esp/v5.1.2/esp-idf/components/bt/include/esp32/include -I/home/santos/Documents/stlab/esp32s3/extra_components/communication -I/home/santos/Documents/stlab/esp32s3/extra_components/mqtts -I/home/santos/Documents/stlab/esp32s3/extra_components/gsm -I/home/santos/Documents/stlab/esp32s3/extra_components/xpower -I/home/santos/Documents/stlab/esp32s3/extra_components/wifi -I/home/santos/Documents/stlab/esp32s3/main

ASM_FLAGS = -mlongcalls 

C_DEFINES = -DMBEDTLS_CONFIG_FILE=\"mbedtls/esp_config.h\" -DSOC_MMU_PAGE_SIZE=CONFIG_MMU_PAGE_SIZE -DUNITY_INCLUDE_CONFIG_H

C_INCLUDES = -I/home/santos/esp/v5.1.2/esp-idf/components/xtensa/include -I/home/santos/esp/v5.1.2/esp-idf/components/xtensa/esp32s3/include -I/home/santos/Documents/stlab/esp32s3/build/config -I/home/santos/esp/v5.1.2/esp-idf/components/newlib/platform_include -I/home/santos/esp/v5.1.2/esp-idf/components/freertos/FreeRTOS-Kernel/include -I/home/santos/esp/v5.1.2/esp-idf/components/freertos/FreeRTOS-Kernel/portable/xtensa/include -I/home/santos/esp/v5.1.2/esp-idf/components/freertos/esp_additions/include/freertos -I/home/santos/esp/v5.1.2/esp-idf/components/freertos/esp_additions/include -I/home/santos/esp/v5.1.2/esp-idf/components/freertos/esp_additions/arch/xtensa/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_hw_support/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_hw_support/include/soc -I/home/santos/esp/v5.1.2/esp-idf/components/esp_hw_support/include/soc/esp32s3 -I/home/santos/esp/v5.1.2/esp-idf/components/esp_hw_support/port/esp32s3/. -I/home/santos/esp/v5.1.2/esp-idf/components/esp_hw_support/port/esp32s3/private_include -I/home/santos/esp/v5.1.2/esp-idf/components/heap/include -I/home/santos/esp/v5.1.2/esp-idf/components/log/include -I/home/santos/esp/v5.1.2/esp-idf/components/soc/include -I/home/santos/esp/v5.1.2/esp-idf/components/soc/esp32s3 -I/home/santos/esp/v5.1.2/esp-idf/components/soc/esp32s3/include -I/home/santos/esp/v5.1.2/esp-idf/components/hal/esp32s3/include -I/home/santos/esp/v5.1.2/esp-idf/components/hal/include -I/home/santos/esp/v5.1.2/esp-idf/components/hal/platform_port/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_rom/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_rom/include/esp32s3 -I/home/santos/esp/v5.1.2/esp-idf/components/esp_rom/esp32s3 -I/home/santos/esp/v5.1.2/esp-idf/components/esp_common/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_system/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_system/port/soc -I/home/santos/esp/v5.1.2/esp-idf/components/esp_system/port/include/private -I/home/santos/esp/v5.1.2/esp-idf/components/lwip/include -I/home/santos/esp/v5.1.2/esp-idf/components/lwip/include/apps -I/home/santos/esp/v5.1.2/esp-idf/components/lwip/include/apps/sntp -I/home/santos/esp/v5.1.2/esp-idf/components/lwip/lwip/src/include -I/home/santos/esp/v5.1.2/esp-idf/components/lwip/port/include -I/home/santos/esp/v5.1.2/esp-idf/components/lwip/port/freertos/include -I/home/santos/esp/v5.1.2/esp-idf/components/lwip/port/esp32xx/include -I/home/santos/esp/v5.1.2/esp-idf/components/lwip/port/esp32xx/include/arch -I/home/santos/esp/v5.1.2/esp-idf/components/esp_ringbuf/include -I/home/santos/esp/v5.1.2/esp-idf/components/efuse/include -I/home/santos/esp/v5.1.2/esp-idf/components/efuse/esp32s3/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/deprecated -I/home/santos/esp/v5.1.2/esp-idf/components/driver/analog_comparator/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/dac/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/gpio/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/gptimer/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/i2c/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/i2s/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/ledc/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/mcpwm/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/parlio/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/pcnt/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/rmt/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/sdio_slave/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/sdmmc/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/sigma_delta/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/spi/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/temperature_sensor/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/touch_sensor/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/twai/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/uart/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/usb_serial_jtag/include -I/home/santos/esp/v5.1.2/esp-idf/components/driver/touch_sensor/esp32s3/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_pm/include -I/home/santos/esp/v5.1.2/esp-idf/components/mbedtls/port/include -I/home/santos/esp/v5.1.2/esp-idf/components/mbedtls/mbedtls/include -I/home/santos/esp/v5.1.2/esp-idf/components/mbedtls/mbedtls/library -I/home/santos/esp/v5.1.2/esp-idf/components/mbedtls/esp_crt_bundle/include -I/home/santos/esp/v5.1.2/esp-idf/components/mbedtls/mbedtls/3rdparty/everest/include -I/home/santos/esp/v5.1.2/esp-idf/components/mbedtls/mbedtls/3rdparty/p256-m -I/home/santos/esp/v5.1.2/esp-idf/components/mbedtls/mbedtls/3rdparty/p256-m/p256-m -I/home/santos/esp/v5.1.2/esp-idf/components/esp_app_format/include -I/home/santos/esp/v5.1.2/esp-idf/components/bootloader_support/include -I/home/santos/esp/v5.1.2/esp-idf/components/bootloader_support/bootloader_flash/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_partition/include -I/home/santos/esp/v5.1.2/esp-idf/components/app_update/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_mm/include -I/home/santos/esp/v5.1.2/esp-idf/components/spi_flash/include -I/home/santos/esp/v5.1.2/esp-idf/components/pthread/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_timer/include -I/home/santos/esp/v5.1.2/esp-idf/components/app_trace/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_event/include -I/home/santos/esp/v5.1.2/esp-idf/components/nvs_flash/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_phy/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_phy/esp32s3/include -I/home/santos/esp/v5.1.2/esp-idf/components/vfs/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_netif/include -I/home/santos/esp/v5.1.2/esp-idf/components/wpa_supplicant/include -I/home/santos/esp/v5.1.2/esp-idf/components/wpa_supplicant/port/include -I/home/santos/esp/v5.1.2/esp-idf/components/wpa_supplicant/esp_supplicant/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_coex/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_wifi/wifi_apps/include -I/home/santos/esp/v5.1.2/esp-idf/components/bt/include/esp32c3/include -I/home/santos/esp/v5.1.2/esp-idf/components/bt/common/osi/include -I/home/santos/esp/v5.1.2/esp-idf/components/bt/common/api/include/api -I/home/santos/esp/v5.1.2/esp-idf/components/bt/common/btc/profile/esp/blufi/include -I/home/santos/esp/v5.1.2/esp-idf/components/bt/common/btc/profile/esp/include -I/home/santos/esp/v5.1.2/esp-idf/components/bt/host/bluedroid/api/include/api -I/home/santos/esp/v5.1.2/esp-idf/components/bt/porting/ext/tinycrypt/include -I/home/santos/esp/v5.1.2/esp-idf/components/unity/include -I/home/santos/esp/v5.1.2/esp-idf/components/unity/unity/src -I/home/santos/esp/v5.1.2/esp-idf/components/cmock/CMock/src -I/home/santos/esp/v5.1.2/esp-idf/components/console -I/home/santos/esp/v5.1.2/esp-idf/components/http_parser -I/home/santos/esp/v5.1.2/esp-idf/components/esp-tls -I/home/santos/esp/v5.1.2/esp-idf/components/esp-tls/esp-tls-crypto -I/home/santos/esp/v5.1.2/esp-idf/components/esp_adc/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_adc/interface -I/home/santos/esp/v5.1.2/esp-idf/components/esp_adc/esp32s3/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_adc/deprecated/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_gdbstub/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_hid/include -I/home/santos/esp/v5.1.2/esp-idf/components/tcp_transport/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_http_client/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_http_server/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_https_ota/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_psram/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_lcd/include -I/home/santos/esp/v5.1.2/esp-idf/components/esp_lcd/interface -I/home/santos/esp/v5.1.2/esp-idf/components/protobuf-c/protobuf-c -I/home/santos/esp/v5.1.2/esp-idf/components/protocomm/include/common -I/home/santos/esp/v5.1.2/esp-idf/components/protocomm/include/security -I/home/santos/esp/v5.1.2/esp-idf/components/protocomm/include/transports -I/home/santos/esp/v5.1.2/esp-idf/components/esp_local_ctrl/include -I/home/santos/esp/v5.1.2/esp-idf/components/espcoredump/include -I/home/santos/esp/v5.1.2/esp-idf/components/espcoredump/include/port/xtensa -I/home/santos/esp/v5.1.2/esp-idf/components/wear_levelling/include -I/home/santos/esp/v5.1.2/esp-idf/components/sdmmc/include -I/home/santos/esp/v5.1.2/esp-idf/components/fatfs/diskio -I/home/santos/esp/v5.1.2/esp-idf/components/fatfs/vfs -I/home/santos/esp/v5.1.2/esp-idf/components/fatfs/src -I/home/santos/esp/v5.1.2/esp-idf/components/idf_test/include -I/home/santos/esp/v5.1.2/esp-idf/components/idf_test/include/esp32s3 -I/home/santos/esp/v5.1.2/esp-idf/components/ieee802154/include -I/home/santos/esp/v5.1.2/esp-idf/components/json/cJSON -I/home/santos/esp/v5.1.2/esp-idf/components/mqtt/esp-mqtt/include -I/home/santos/esp/v5.1.2/esp-idf/components/perfmon/include -I/home/santos/esp/v5.1.2/esp-idf/components/spiffs/include -I/home/santos/esp/v5.1.2/esp-idf/components/touch_element/include -I/home/santos/esp/v5.1.2/esp-idf/components/ulp/ulp_common/include -I/home/santos/esp/v5.1.2/esp-idf/components/ulp/ulp_common/include/esp32s3 -I/home/santos/esp/v5.1.2/esp-idf/components/usb/include -I/home/santos/esp/v5.1.2/esp-idf/components/wifi_provisioning/include -I/home/santos/Documents/stlab/esp32s3/extra_components/uart -I/home/santos/Documents/stlab/esp32s3/extra_components/storage -I/home/santos/Documents/stlab/esp32s3/extra_components/devices -I/home/santos/esp/v5.1.2/esp-idf/components/bt/include/esp32/include -I/home/santos/Documents/stlab/esp32s3/extra_components/communication -I/home/santos/Documents/stlab/esp32s3/extra_components/mqtts -I/home/santos/Documents/stlab/esp32s3/extra_components/gsm -I/home/santos/Documents/stlab/esp32s3/extra_components/xpower -I/home/santos/Documents/stlab/esp32s3/extra_components/wifi -I/home/santos/Documents/stlab/esp32s3/main

C_FLAGS = -mlongcalls 
