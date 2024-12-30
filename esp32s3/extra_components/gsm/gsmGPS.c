/**
 * @file gsmGPS.c
 * @author Luis Santos (luis.santos@logpyx.com)
 * @brief 
 * 
 * @version 1.0.0
 * @date 2024-05
 * 
 * @attention
 * 
 * <h2><center>&copy; COPYRIGHT 2023 LogPyx S/A</center></h2>
 * 
 */

#include "gsmGPS.h"

gsm_gps_config_t gsm_gps_config;

static uint8_t gsmGpsAnswer[UART_BUFFER_SIZE] = {0};
static char commandGps[UART_BUFFER_SIZE];

static char strftime_buf[64];
/**
 * @brief Get the current time from ESP clock
 * @param none
 * @retval char* current time
 */
char *gsmGpsGetCurrentTime(void) {
    memset(strftime_buf, 0, sizeof(strftime_buf));
    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);
    strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);
    return strftime_buf;
}

/**
 * @brief Get the current time from modem and set ESP clock
 * @param none
 * @retval none
 */
void gsmGpsGetAndSetCurrentTime(void) {
    snprintf(commandGps, sizeof(commandGps), "%s%s%s", GMS_MODEM_AT, "+CGNSINF", GSM_MODEM_NL);
    gsmModemCommand(commandGps, gsmGpsAnswer, GSM_MODEM_OK);

    double date;
    gsmModemGetValue((const char*)gsmGpsAnswer, 2, &date);
    
    char time_string[15];
    sprintf(time_string, "%.0f", date);


    int yy, mm, dd, hh, mi, ss;
    sscanf(time_string, "%4d%2d%2d%2d%2d%2d", &yy, &mm, &dd, &hh, &mi, &ss);

    struct tm timer = {0};
    timer.tm_year = yy - 1900;
    timer.tm_mon = mm - 1;
    timer.tm_mday = dd;
    timer.tm_hour = hh;
    timer.tm_min = mi;
    timer.tm_sec = ss;
    timer.tm_isdst = -1;
    time_t time_since_epoch = mktime(&timer);
    struct timeval now = { .tv_sec = time_since_epoch };
    settimeofday(&now, NULL);
    return;
}

/**
 * @brief Função get para struct do componente
 * @param None
 * @retval referencia para a struct
 */
gsm_gps_config_t gsmGpsGetConfig(void) {
    return gsm_gps_config;
}

/**
 * @brief Função set para struct do componente
 * @param gps_config referencia para a struct
 * @retval None
 */
void gsmGpsSetConfig(gsm_gps_config_t gps_config) {
    gsm_gps_config = gps_config;
}

/**
 * @brief Função de sincronização temporal do módulo 
 * @param None
 * @retval none
 */
void gsmGpsGetLocalTimestamp(void) {
    snprintf(commandGps, sizeof(commandGps), "%s%s%s", GMS_MODEM_AT, "+CLTS=1", GSM_MODEM_NL);
    switch (gsmModemCommand(commandGps, gsmGpsAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_GPS, "Get local timestamp error");
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "Get local timestamp sucessfully");
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "Get local timestamp unsucessfully");
            break;
    }
    return;
}

/**
 * @brief Função de verificação se existe na flash o arquivo XTRA
 * @param None
 * @retval bool
 */
bool gsmGpsVerifyXtraFile(void) {
    snprintf(commandGps, sizeof(commandGps), "%s%s%s", GMS_MODEM_AT, "+CFSGFIS=3,\"Xtra3.bin\"", GSM_MODEM_NL);
    switch (gsmModemCommand(commandGps, gsmGpsAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_GPS, "XTRA file error");
            return false;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "XTRA file exist");
            return true;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "XTRA file doesn't exist");
            return false;
    }
    return false;
}

/**
 * @brief Função de download do arquivo XTRA
 * @param None
 * @retval bool
 */
void gsmGpsDownloadXtraFile(void) {
    double status = 1.0;
    snprintf(commandGps, sizeof(commandGps), "%s%s\"%s\",\"%s\"%s", GMS_MODEM_AT, "+HTTPTOFS=", GSM_GPS_XTRA_FILE_URL, GSM_GPS_XTRA_FILE_DESTINY, GSM_MODEM_NL);
    switch(gsmModemCommand(commandGps, gsmGpsAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_GPS, "XTRA file download error");
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            snprintf(commandGps, sizeof(commandGps), "%s%s%s", GMS_MODEM_AT, "+HTTPTOFSRL?", GSM_MODEM_NL);
            while (1) {
                gsmModemCommand(commandGps, gsmGpsAnswer, GSM_MODEM_OK);
                gsmModemGetValue((const char*)gsmGpsAnswer, 0, &status);
                if((int)status == 0){
                    ESP_LOGI(TAG_GPS, "XTRA file download sucessfully");
                    return;
                }
                vTaskDelay(pdMS_TO_TICKS(5000));
            }
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "XTRA file download unsucessfully");
            break;
    }
    return;
}

/**
 * @brief Função de sincronização temporal do módulo 
 * @param None
 * @retval none
 */
void gsmModemSetXtraFile(void) {
    snprintf(commandGps, sizeof(commandGps), "%s%s%s", GMS_MODEM_AT, "+CGNSCPY", GSM_MODEM_NL);
    gsmModemCommand(commandGps, gsmGpsAnswer, GSM_MODEM_OK);

    snprintf(commandGps, sizeof(commandGps), "%s%s%s", GMS_MODEM_AT, "+CGNSXTRA", GSM_MODEM_NL);
    gsmModemCommand(commandGps, gsmGpsAnswer, GSM_MODEM_OK);

    snprintf(commandGps, sizeof(commandGps), "%s%s%s", GMS_MODEM_AT, "+CGNSXTRA=1", GSM_MODEM_NL);
    gsmModemCommand(commandGps, gsmGpsAnswer, GSM_MODEM_OK);
}

/**
 * @brief Desabilita GPS
 * @param None
 * @retval None
 */
void gsmGpsDisableGps(void) {
    snprintf(commandGps, sizeof(commandGps), "%s%s%s", GMS_MODEM_AT, "+CGNSPWR=0", GSM_MODEM_NL);
    switch (gsmModemCommand(commandGps, gsmGpsAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_GPS, "Disable GPS failed");
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "Disable GPS successfully\n");
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "Disable GPS unsuccessfully\n");
            break;
    }
    vTaskDelay(pdMS_TO_TICKS(1000));
    return;
}

/**
 * @brief Habilita hot GPS
 * @param None
 * @retval None
 */
void gsmGpsHotGps(void) {
    snprintf(commandGps, sizeof(commandGps), "%s%s%s", GMS_MODEM_AT, "+CGNSHOT", GSM_MODEM_NL);
    switch (gsmModemCommand(commandGps, gsmGpsAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_GPS, "Hot GPS failed");
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "Hot GPS successfully\n");
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "Hot GPS unsuccessfully\n");
            break;
    }
    return;
}

/**
 * @brief Define o modo de trabalho 
 * @param None
 * @retval None
 */
void gsmGpsSetWorkMode(void) {
    snprintf(commandGps, sizeof(commandGps), "%s%s%d"",""%d"",""%d"",""%d"",""%d%s", GMS_MODEM_AT, "+CGNSMOD=", 
                gsm_gps_config.gsm_gps_work_mode.gps,
                    gsm_gps_config.gsm_gps_work_mode.glo,
                        gsm_gps_config.gsm_gps_work_mode.bd,
                            gsm_gps_config.gsm_gps_work_mode.gal,
                                gsm_gps_config.gsm_gps_work_mode.qzss,
                                    GSM_MODEM_NL);

    switch (gsmModemCommand(commandGps, gsmGpsAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_GPS, "Define GPS work mode failed");
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "Define GPS work mode successfully\n");
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "Define GPS work mode unsuccessfully\n");
            break;
    }
    return;
}

/**
 * @brief Define o modo de trabalho do GPS/GNSS
 * @param None
 * @retval None
 */
void gsmGpsCommand(void) {
    snprintf(commandGps, sizeof(commandGps), "%s%s%d"",""%d"",""%d"",""%d%s", GMS_MODEM_AT, "+SGNSCMD=", 
                gsm_gps_config.gsm_gps_command.mode,
                    gsm_gps_config.gsm_gps_command.minInterval,
                        gsm_gps_config.gsm_gps_command.minDistance,
                            gsm_gps_config.gsm_gps_command.accuracy,
                                GSM_MODEM_NL);
    switch (gsmModemCommand(commandGps, gsmGpsAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_GPS, "Define GPS command failed");
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "Define GPS command successfully\n");
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "Define GPS command unsuccessfully\n");
            break;
    }
    return;
}

/**
 * @brief Desligua o GNSS (não sei porque/deve ser porque GPRS E GNSS não podem funcionar mutualmente)
 * @param None
 * @retval None
 */
void gsmGpsTurnOffGnss(void) {
    snprintf(commandGps, sizeof(commandGps), "%s%s%s", GMS_MODEM_AT, "+SGNSCMD=0", GSM_MODEM_NL);
    switch (gsmModemCommand(commandGps, gsmGpsAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_GPS, "Turn off GNSS command failed");
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "Turn off GNSS command successfully\n");
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "Turn off GNSS command unsuccessfully\n");
            break;
    }
    vTaskDelay(pdMS_TO_TICKS(500));
    return;
}

/**
 * @brief Liga o GNSS
 * @param None
 * @retval None
 */
void gsmGpsTurnOnGnss(void) {
    snprintf(commandGps, sizeof(commandGps), "%s%s%s", GMS_MODEM_AT, "+SGNSCMD=1", GSM_MODEM_NL);
    switch (gsmModemCommand(commandGps, gsmGpsAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_GPS, "Turn on GNSS command failed");
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "Turn on GNSS command successfully\n");
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "Turn on GNSS command unsuccessfully\n");
            break;
    }
    return;
}

/**
 * @brief Habilita GPS
 * @param None
 * @retval None
 */
void gsmGpsEnableGps(void) {
    snprintf(commandGps, sizeof(commandGps), "%s%s%s", GMS_MODEM_AT, "+CGNSPWR=1", GSM_MODEM_NL);
    switch (gsmModemCommand(commandGps, gsmGpsAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_GPS, "Enable GPS failed");
            break;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "Enable GPS successfully\n");
            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "Enable GPS unsuccessfully\n");
            break;
    }
    vTaskDelay(pdMS_TO_TICKS(1000));
    return;
}

/**
 * @brief Envia comando de requerimento da localização do GPS
 * @param None
 * @retval uint8_t flag gps fix position or 
 */
uint8_t gsmGpsGetGps(void) {
    static uint8_t same_coordinates = 0;

    snprintf(commandGps, sizeof(commandGps), "%s%s%s", GMS_MODEM_AT, "+CGNSINF", GSM_MODEM_NL);
    switch (gsmModemCommand(commandGps, gsmGpsAnswer, GSM_MODEM_OK)) {
        case GSM_MODEM_NO_ANSWER:
            ESP_LOGI(TAG_GPS, "Get GPS error. Restarting ESP32...");
            esp_restart();
            return false;
        
        case GSM_MODEM_EXPECTED_ANSWER:
            double latitude = 0.0, longitude = 0.0, velocidade = 0.0;
            gsmModemGetValue((const char*)gsmGpsAnswer, 3, &latitude);
            gsmModemGetValue((const char*)gsmGpsAnswer, 4, &longitude);
            gsmModemGetValue((const char*)gsmGpsAnswer, 6, &velocidade);

            if(latitude != 0.0 && longitude != 0.0 && latitude != GSM_GPS_INVALID_LATITUDE && longitude != GSM_GPS_INVALID_LONGITUDE) {
                if(latitude == gsm_gps_config.gsm_gps_coordenadas.last_latitude && longitude == gsm_gps_config.gsm_gps_coordenadas.last_longitude) {
                    same_coordinates++;
                    if(same_coordinates >= GSM_GPS_MAX_REPEATED_COORDINATES) {
                        ESP_LOGE(TAG_GPS, "Máxima repetição de coordenadas atingida. Restarting ESP and Modem...");
                        gsmModemRestartModem();
                        esp_restart();
                    }   
                } else {
                    same_coordinates = 0;
                }

                gsm_gps_config.gsm_gps_coordenadas.latitudes[gsm_gps_config.gsm_gps_coordenadas.count]     = latitude;
                gsm_gps_config.gsm_gps_coordenadas.longitudes[gsm_gps_config.gsm_gps_coordenadas.count]    = longitude;
                gsm_gps_config.gsm_gps_coordenadas.speeds[gsm_gps_config.gsm_gps_coordenadas.count]        = velocidade;
                gsm_gps_config.gsm_gps_coordenadas.count ++;

                gsm_gps_config.gsm_gps_coordenadas.last_latitude    = latitude;
                gsm_gps_config.gsm_gps_coordenadas.last_longitude   = longitude; 
                gsm_gps_config.gsm_gps_coordenadas.last_speed       = velocidade;
            }

            break;

        case GSM_MODEM_NO_EXPECTED_ANSWER:
            ESP_LOGI(TAG_GPS, "Get GPS unsuccessfully");
            gsmModemRestartModem();
            esp_restart();
            return false;
    }
    
    return false;
}

/**
 * @brief Função que calcula a media retirando os valores fora do desvio padrão
 * @param double data array que se deseja calcular a media
 * @retval double media
 */
double gsmGpsCalculaMediaDesvioPadrao(double *data) {
    double media = 0.0, soma = 0.0;
    for (uint8_t i = 0; i < gsm_gps_config.gsm_gps_coordenadas.count; i++) {
        soma += data[i];
    }

    if(gsm_gps_config.gsm_gps_coordenadas.count != 0) {
        media = soma / gsm_gps_config.gsm_gps_coordenadas.count;
        if(gsm_gps_config.gsm_gps_coordenadas.count >= 2) {
            double desvio_padrao = 0.0;
            soma = 0.0;
            for (uint8_t i = 0; i < gsm_gps_config.gsm_gps_coordenadas.count; i++) {
                double diferenca = data[i] - media;
                double quadrado_diferenca = pow(diferenca, 2);
                soma += quadrado_diferenca;
            }
            desvio_padrao = sqrt(soma / gsm_gps_config.gsm_gps_coordenadas.count);
            soma = 0.0;
            int count_validos = 0;
            for (uint8_t i = 0; i < gsm_gps_config.gsm_gps_coordenadas.count; i++) {
                if (data[i] > (media - desvio_padrao) && data[i] < (media + desvio_padrao)) {
                    soma += data[i];
                    count_validos++;
                }
            }

            if (count_validos != 0) {
                double media_desvio_padrao = soma / count_validos;
                return media_desvio_padrao;
            }
        }
        return media;
    }
    return 0.0;
}

/**
 * @brief Função get gps por um tempo determinado
 * @param int time tempo desejado
 * @retval None
 */
void gsmGpsGetGpsForTime(int time) {
    memset(gsm_gps_config.gsm_gps_coordenadas.latitudes, 0, sizeof(gsm_gps_config.gsm_gps_coordenadas.latitudes));
    memset(gsm_gps_config.gsm_gps_coordenadas.longitudes, 0, sizeof(gsm_gps_config.gsm_gps_coordenadas.longitudes));
    memset(gsm_gps_config.gsm_gps_coordenadas.speeds, 0, sizeof(gsm_gps_config.gsm_gps_coordenadas.speeds));
    gsm_gps_config.gsm_gps_coordenadas.count = 0;
    
    gsmGpsHotGps();

    gsmGpsEnableGps();

    if(time == GSM_GPS_GET_GPS_MAX_TIME) {
        TickType_t gsm_gps_time_max = pdMS_TO_TICKS(GSM_GPS_GET_GPS_MAX_TIME);
        TickType_t gsm_gps_time_init = xTaskGetTickCount();
        while(gsm_gps_config.gsm_gps_coordenadas.count < GSM_GPS_GET_GPS_MIN_VALID_COORDINATES) {
            gsmGpsGetGps();
            vTaskDelay(pdMS_TO_TICKS(gsm_gps_config.gsm_gps_command.minInterval));
            if((xTaskGetTickCount() - gsm_gps_time_init) > gsm_gps_time_max){
                gsmModemRestartModem();
                esp_restart();
            }
        }
    }

    if(time == GSM_GPS_GET_GPS_TIME_SUBSEQUENT) {
        TickType_t gsm_gps_time_max = pdMS_TO_TICKS(time);
        TickType_t gsm_gps_time_init = xTaskGetTickCount();
        while((xTaskGetTickCount() - gsm_gps_time_init) < gsm_gps_time_max) {
            gsmGpsGetGps();
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }

    /*
    for(uint8_t j = 0; j < gsm_gps_config.gsm_gps_coordenadas.count; j++) {
        ESP_LOGI(TAG_GPS, "Latitude[%d]: %f Longitude[%d]: %f Speed[%d]: %f", 
            j, 
                gsm_gps_config.gsm_gps_coordenadas.latitudes[j], 
                    j, 
                        gsm_gps_config.gsm_gps_coordenadas.longitudes[j], 
                            j, 
                                gsm_gps_config.gsm_gps_coordenadas.speeds[j]);
    }
    */

    if(time == GSM_GPS_GET_GPS_MIN_VALID_COORDINATES) {
        gsmGpsGetAndSetCurrentTime();
    }

    gsmGpsDisableGps();
    return;
}

/**
 * @brief Função de inicialização do componente GPS
 * @param None
 * @retval None
 */
void gsmGpsInit(void) {
    GSM_GPS_CONFIG_DEAFULT(gsm_gps_config);

    gsmGpsDisableGps();

    gsmGpsGetLocalTimestamp();
    /*
    if(!(gsmGpsVerifyXtraFile() == GSM_GPS_XTRA_FILE_EXIST)) {
        gsmGpsDownloadXtraFile();
    }

    gsmModemSetXtraFile();
    */
    gsmGpsSetWorkMode();

    gsmGpsCommand();

    gsmGpsTurnOffGnss();

    gsmGpsGetGpsForTime(GSM_GPS_GET_GPS_MAX_TIME);
}