/**
 * @file wifi_main.c
 * @author Luis Santos (luis.santos@logpyx.com)
 * @brief Componente responsável por realizar a efetica conexão WIFI
 * 
 * @version 2.0.0
 * @date 2024-03
 * 
 * @attention
 * 
 * <h2><center>&copy; COPYRIGHT 2023 LogPyx S/A</center></h2>
 * 
 */

#include "wifi_headers.h"

EventGroupHandle_t wifi_event_group;        /*!< Grupo de eventos WIFI*/

static uint8_t check_connect_times=0;       /*!< Variável contadora de tentativas de reconexão*/
static uint8_t check_reboot_times=0;        /*!< Variável contadora para o reboot*/

wifi_data_base_t wifi_data_base;

/**
 * @brief Handle de conexão e status IP
 * 
 * @param none
 * @return none
 */
static void ip_event_handler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data){
    wifi_mode_t mode;
    switch (event_id) {
    case IP_EVENT_STA_GOT_IP: {
    	ESP_LOGI(TAG_WIFI, "SET STATUS_WIFI_GOT_IP_BIT");
		xEventGroupSetBits(wifi_event_group, WIFI_CONNECTED_BIT);
		break;
    }
    default:
        break;
    }

    return;
}

/**
 * @brief Handle de conexão e status WIFI
 * 
 * @param none
 * @return none
 */
static void wifi_event_handler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data){
    wifi_event_sta_connected_t *event;
    wifi_mode_t mode;

    switch (event_id) {
    case WIFI_EVENT_STA_START:
    	ESP_LOGI(TAG_WIFI, "WIFI_EVENT_STA_START");
        esp_wifi_connect();
        break;

    case WIFI_EVENT_STA_CONNECTED:
    	ESP_LOGI(TAG_WIFI, "WIFI_EVENT_STA_CONNECTED");
        xEventGroupSetBits(wifi_event_group, WIFI_CONNECTED_BIT);
        xEventGroupClearBits(wifi_event_group, WIFI_DISCONNECTED_BIT);
        check_connect_times=0;
        check_reboot_times=0;
        break; 

    case WIFI_EVENT_STA_DISCONNECTED:
    	ESP_LOGI(TAG_WIFI, "WIFI_EVENT_STA_DISCONNECTED");
    	xEventGroupSetBits(wifi_event_group, WIFI_DISCONNECTED_BIT);
        xEventGroupClearBits(wifi_event_group, WIFI_CONNECTED_BIT);
        esp_wifi_connect();

        if(check_connect_times>WIFI_MONITOR_WATCHDOG_CONNECTION_WIFI){
            esp_wifi_stop();
        }
        else {
            check_connect_times++;
        }
        break;

    case WIFI_EVENT_AP_START:
    	ESP_LOGI(TAG_WIFI, "WIFI_EVENT_AP_START");
    	esp_wifi_get_mode(&mode);
        break;

    case WIFI_EVENT_STA_STOP:
    	ESP_LOGI(TAG_WIFI, "WIFI_EVENT_STA_STOP");
    	if(check_reboot_times>WIFI_MONITOR_WATCHDOG_REBOOT){
            //esp_restart();
        }
    	else{
            check_reboot_times++;
        }
    	check_connect_times=0;
    	esp_wifi_start();
    	break;

    case WIFI_EVENT_SCAN_DONE: {
    	ESP_LOGI(TAG_WIFI, "WIFI_EVENT_SCAN_DONE");
        esp_wifi_scan_stop();
        break;
    }
    default:
        break;
    }
    return;
}

/**
 * @brief Função get para um ponteiro struct estatica wifi_data_base_t
 * 
 * @param none
 * @return ponteiro para um ponteiro struct estatica wifi_data_base_t
 */
wifi_data_base_t *wifiGetPointerWifiConfig(void){
    return &wifi_data_base;
}

/**
 * @brief Função get para uma referência struct estatica wifi_data_base_t
 * 
 * @param none
 * @return ponteiro para uma referência struct estatica wifi_data_base_t
 */
wifi_data_base_t wifiGetWifiConfig(void){
    return wifi_data_base;
}

/**
 * @brief Função get para eventos WIFI
 * 
 * @param none
 * @return referência dos eventos WIFI
 */
EventGroupHandle_t wifiGetWifiEventGroup(void){
    return wifi_event_group;
}

/**
 * @brief Função get do MAC WIFI para gravação na struct de dados wifi_data_base_t
 * 
 * @param none
 * @return none
 */
void wifiGetMac(void) {
    ESP_LOGI(TAG_WIFI, "Initializing wifiGetMac...");

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_err_t err = esp_wifi_init(&cfg);
    if (err != ESP_OK) {
        ESP_LOGE(TAG_WIFI, "Erro ao inicializar o Wi-Fi: %s", esp_err_to_name(err));
        return;
    }

    err = esp_wifi_start();
    if (err != ESP_OK) {
        ESP_LOGE(TAG_WIFI, "Erro ao iniciar o Wi-Fi: %s", esp_err_to_name(err));
        return;
    }

    err = esp_wifi_get_mac(ESP_IF_WIFI_STA, wifi_data_base.mac);
    if (err != ESP_OK) {
        ESP_LOGE(TAG_WIFI, "Erro ao obter o endereço MAC: %s", esp_err_to_name(err));
        return;
    }

    err = esp_wifi_stop();
    if (err != ESP_OK) {
        ESP_LOGE(TAG_WIFI, "Erro ao encerrar o Wi-Fi: %s", esp_err_to_name(err));
        return;
    }
}

/**
 * @brief Função de inicialização do componente WIFI
 * 
 * @param none
 * @return none
 */
void wifiInit(void){
    wifi_event_group = xEventGroupCreate();

    WIFI_DATA_BASE_DEFAULT(wifi_data_base);

    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta();
    assert(sta_netif);

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL));
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &ip_event_handler, NULL));

    wifi_config_t wifi_config = {
        .sta = {
            .ssid = "",
            .password = "",
        }
    };

    strcpy((char *)wifi_config.sta.ssid, wifi_data_base.ssid);
    strcpy((char *)wifi_config.sta.password, wifi_data_base.pwd);

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA) );
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config) );
    ESP_ERROR_CHECK(esp_wifi_start() );

    ESP_LOGI(TAG_WIFI, "Start WiFi...");
}