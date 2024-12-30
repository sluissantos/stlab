idf_component_register( SRCS            "gsmModem.c" "gsmGPS.c" "gsmMQTT.c"
                        INCLUDE_DIRS    "."
                        REQUIRES        esp_wifi
                                        wpa_supplicant
                                        freertos
                                        nvs_flash
                                        spi_flash
                                        esp_event
                                        driver
                                        uart
                                        esp_timer
                                        communication
                                        xpower
                        )