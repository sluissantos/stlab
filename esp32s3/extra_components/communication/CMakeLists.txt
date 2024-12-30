idf_component_register( SRCS "communication.c"
                        INCLUDE_DIRS "."
                        REQUIRES 
                                uart 
                                devices 
                                mqtts
                                gsm
                                )
