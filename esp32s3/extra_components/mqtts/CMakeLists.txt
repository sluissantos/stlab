
idf_component_register( SRCS            "mqtts_main.c"
                        INCLUDE_DIRS    "."
                        REQUIRES        nvs_flash
                                        esp_event
                                        freertos
                                        spi_flash
                                        esp_netif
                                        esp_wifi
                                        driver
                                        mqtt
                                        esp_system
                                        storage
)                   