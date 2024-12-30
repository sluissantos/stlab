idf_component_register( SRCS "devices_main.c"
                        INCLUDE_DIRS "." 
                            "${IDF_PATH}/components/nvs_flash/include"
                            "${IDF_PATH}/components/spi_flash/include"
                            "${IDF_PATH}/components/bt/include/esp32/include"
                            "${IDF_PATH}/components/bt/host/bluedroid/api/include/api"
                        REQUIRES 
                                communication 
                                storage 
                                heap
                        )