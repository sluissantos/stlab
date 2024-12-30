idf_component_register( SRCS            "xpowermain.c"
                        INCLUDE_DIRS    "."
                        REQUIRES        esp_wifi
                                        wpa_supplicant
                                        freertos
                                        nvs_flash
                                        spi_flash
                                        esp_event
                                        driver
                        )