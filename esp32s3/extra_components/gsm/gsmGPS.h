/**
 * @file gsmGPS.h
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

#pragma once

#include <math.h>
#include "gsmModem.h"
#include "esp_system.h"
#include "esp_types.h"

/**
 * @brief Macro de definição da TAG
 */
#define TAG_GPS                                 "GPS" 

/**
 * @brief Macro de definição da quantidade de coordenadas GPS válidas mínimas para o primeiro requerimento
 */
#define GSM_GPS_GET_GPS_MIN_VALID_COORDINATES   30

/**
 * @brief Macro de definição do tempo máximo para coletar as coordenadas para o primeiro requerimento, em ms
 */
#define GSM_GPS_GET_GPS_MAX_TIME                300000

/**
 * @brief Macro de definição do tempo padrão de requerimento GPS, em ms
 */
#define GSM_GPS_GET_GPS_TIME_SUBSEQUENT         15000

/**
 * @brief Macro de definição do valor máximo de repetição das coordenadas adquiridas no GPS
 */
#define GSM_GPS_MAX_REPEATED_COORDINATES        60

/**
 * @brief Macro de definição flag gps fix position
 */
#define GSM_GPS_FIXED_POSITION                  1

/**
 * @brief Macro de definição do valor invalido de latitude
 */
#define GSM_GPS_INVALID_LATITUDE                -13.000002

/**
 * @brief Macro de definição do valor invalido de longitude
 */
#define GSM_GPS_INVALID_LONGITUDE               -54.000002

/**
 * @brief Macro de definição do valor de quantidades máximas
 */
#define GSM_GPS_MAX_COORDINATES                 50

/**
 * @brief Macro de definição do limite de velocidade para considerar que o modulo esta parado
 */
#define GSM_GPS_VELOCITY_THRESHOLD              3.0

/**
 * @brief Macro de definição do url do servidor XTRA
 */
#define GSM_GPS_XTRA_FILE_URL                   "http://iot2.xtracloud.net/xtra3gr_72h.bin"

/**
 * @brief Macro de definição do destino do arquivo XTRA no sistema de arquivos do módulo
 */
#define GSM_GPS_XTRA_FILE_DESTINY               "/customer/Xtra3.bin"

/**
 * @brief Macro de definição da flag caso o arquivo XTRA já exista na flash
 */
#define GSM_GPS_XTRA_FILE_EXIST                 1

/**
 * @brief Definine a configuração default para a rede GPS
 */
#define GSM_GPS_CONFIG_DEAFULT(config) do {                     \
    (config).gsm_gps_work_mode.gps              =   1;          \
    (config).gsm_gps_work_mode.glo              =   1;          \
    (config).gsm_gps_work_mode.bd               =   0;          \
    (config).gsm_gps_work_mode.gal              =   0;          \
    (config).gsm_gps_work_mode.qzss             =   0;          \
    (config).gsm_gps_command.mode               =   2;          \
    (config).gsm_gps_command.minInterval        =   1000;       \
    (config).gsm_gps_command.minDistance        =   0;          \
    (config).gsm_gps_command.accuracy           =   0;          \
    (config).gsm_gps_coordenadas.last_latitude  =   0.0;        \
    (config).gsm_gps_coordenadas.last_longitude =   0.0;        \
    (config).gsm_gps_coordenadas.last_speed     =   0.0;        \
    memset((config).gsm_gps_coordenadas.latitudes, 0, sizeof((config).gsm_gps_coordenadas.latitudes));      \
    memset((config).gsm_gps_coordenadas.longitudes, 0, sizeof((config).gsm_gps_coordenadas.longitudes));    \
    memset((config).gsm_gps_coordenadas.speeds, 0, sizeof((config).gsm_gps_coordenadas.speeds));            \
    (config).gsm_gps_coordenadas.count          =   0;          \
} while(0);

/**
 * @brief Macro de definição da struct do componente
 */
typedef struct {
    struct{
        double latitudes[GSM_GPS_MAX_COORDINATES];          /*!< GPS total latitude*/
        double longitudes[GSM_GPS_MAX_COORDINATES];         /*!< GPS total longitude*/
        double speeds[GSM_GPS_MAX_COORDINATES];             /*!< GPS velocidade */
        uint8_t count;                                     /*!< GPS quantidade de coordenadas */
        double last_latitude;       /*!< GPS last latitude*/
        double last_longitude;      /*!< GPS last longitude*/
        double last_speed;          /*!< GPS last velocidade*/
    }gsm_gps_coordenadas;

    struct{
        uint8_t gps;            /*!< Allow GPS NMEA */
        uint8_t glo;            /*!< Allow GLO NMEA */
        uint8_t bd;             /*!< Allow BD NMEA */
        uint8_t gal;            /*!< Allow GAL NMEA */
        uint8_t qzss;           /*!< Allow QZSS NMEA */
    }gsm_gps_work_mode;

    struct{
        uint8_t mode;           /*!< 0 Turn off GNSS */
                                /*!< 1 Turn on GNSS and get location information once */
                                /*!< 2 Turn on GNSS and get multiple location information */

        uint16_t minInterval;   /*!< minInterval is the minimum time interval in milliseconds that must 
                                   elapse between position reports. default value is 1000 */

        uint16_t minDistance;   /*!< Minimum distance in meters that must be traversed between position
                                   reports. Setting this interval to 0 will be a pure time-based tracking/batching */

        uint8_t accuracy;       /*!< 0 Accuracy is not specified, use default */
                                /*!< 1 Low Accuracy for location is acceptable */
                                /*!< 2 Medium Accuracy for location is acceptable */
                                /*!< 3 Only High Accuracy for location is acceptable */

    }gsm_gps_command;

} gsm_gps_config_t;

void gsmGpsInit(void);
void gsmGpsEnableGps(void);
void gsmGpsDisableGps(void);
gsm_gps_config_t gsmGpsGetConfig(void);
void gsmGpsSetConfig(gsm_gps_config_t config);
void gsmGpsGetGpsForTime(int time);
char *gsmGpsGetCurrentTime(void);
void gsmGpsGetAndSetCurrentTime(void);
double gsmGpsCalculaMedia(double *data);
double gsmGpsCalculaMediaDesvioPadrao(double *data);