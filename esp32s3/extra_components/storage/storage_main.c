/**
 * @file storage_main.c
 * @author Luis Santos (luis.santos@logpyx.com)
 * @author Luis Henrique Maciel (luis@logpyx.com)
 * @author Henrique Ferreira (henrique.ferreira@logpyx.com)
 * @brief Esse arquivo apresenta as funções para leitura e escrita nas partições de armazenamento
 * para realizar tanto a configuração geral do Aura quanto das variáveis internas.  
 * 
 * @version 2.0.0
 * @date 2024-04
 * 
 * @attention
 * 
 * <h2><center>&copy; COPYRIGHT 2023 LogPyx S/A</center></h2>
 * 
 */

#include "storage_headers.h"
#include "nvs_flash.h"
#include "esp_system.h"
#include "esp_log.h"

nvs_handle_t storageHandler;            /*!< Declara handle da nvs padrão*/

size_t required_size;                   /*!< Variábel para o tamanho do dado*/

SemaphoreHandle_t mutex_storage_blob;   /*!< Declara mutex para o componente storage blob*/

/**
 * @brief Abertura do handler na partição de armazenamento
 * 
 * @param  None
 * @retval None
 */
void storageOpen(void){
    esp_err_t err = nvs_open(NVS_STORAGE_PARTITION, NVS_READWRITE, &storageHandler);
    ESP_ERROR_CHECK(err);
}

/**
 * @brief Fechamento do handler na partição de armazenamento
 * 
 * @param  None
 * @retval None
 */
void storageCloseHandler(void){
    nvs_close(storageHandler);
}

/**
 * @brief Realiza a verificação de erro da instrução de acesso a NVS e faz
 *        o commit do comando de escrita 
 * 
 * @param err flag de erro realicionada com o comando de acesso realizado anteriormente 
 * @param storageHandler handler da NVS utilizado no comando de acesso
 * @retval None
 */
void storageCheckErrorAndCommit(esp_err_t err, nvs_handle_t handler){
    ESP_ERROR_CHECK(err);
    err = nvs_commit(handler);
    ESP_ERROR_CHECK(err);
    nvs_close(handler);
}


/**
 * @brief Realiza o processo de leitura na NVS para uma variável do tipo uint32
 * 
 * @note Caso o dado buscado na partição de storage não seja encontrado, é lido o
 * valor da variável correspondente dentro das configurações de fábrica
 * 
 * @param nvs_key label que define o local em que o dado deve ser buscado 
 * @param int_data valor que foi encontrada dentro da NVS
 * @retval None
 */
void storageGetUint32(char* nvs_key, uint32_t* int_data){
    storageOpen();
    esp_err_t err = nvs_get_u32(storageHandler, nvs_key, int_data);
    if(err != ESP_OK){
        ESP_LOGE(TAG_STORAGE, "Erro ao recuperar o uint32 %s da NVS: %s", nvs_key, esp_err_to_name(err));
        storageCloseHandler();
        return;
    }
    storageCloseHandler();
    ESP_LOGI(TAG_STORAGE,"%s(r) %ld", nvs_key, *int_data);
}

/**
 * @brief Realiza o processo de escrita na NVS para uma variável do tipo uint32
 * 
 * @param nvs_key label que define o local em que o dado deve ser salvo na NVS
 * @param int_data valor que será salvo na NVS
 * @retval None
 */
void storageSetUint32(char* nvs_key, uint32_t* int_data){
    storageOpen();
    esp_err_t err = nvs_set_u32(storageHandler, nvs_key, *int_data);
    storageCheckErrorAndCommit(err, storageHandler);
    ESP_LOGI(TAG_STORAGE,"%s(w) %ld", nvs_key, *int_data);
}


/**
 * @brief Realiza o processo de leitura na NVS para uma variável do tipo uint16
 * 
 * @note Caso o dado buscado na partição de storage não seja encontrado, é lido o
 * valor da variável correspondente dentro das configurações de fábrica
 * 
 * @param nvs_key label que define o local em que o dado deve ser buscado 
 * @param int_data valor que foi encontrada dentro da NVS
 * @retval None
 */
void storageGetUint16(char* nvs_key, uint16_t* int_data){
    storageOpen();
    esp_err_t err = nvs_get_u16(storageHandler, nvs_key, int_data);
    if(err != ESP_OK){
        ESP_LOGE(TAG_STORAGE, "Erro ao recuperar o uint16 %s da NVS: %s", nvs_key, esp_err_to_name(err));
        storageCloseHandler();
        return;
    }
    storageCloseHandler();
    ESP_LOGI(TAG_STORAGE,"%s(r) %d", nvs_key, *int_data);
}

/**
 * @brief Realiza o processo de escrita na NVS para uma variável do tipo uint16
 * 
 * @param nvs_key label que define o local em que o dado deve ser salvo na NVS
 * @param int_data valor que será salvo na NVS
 * @retval None
 */
void storageSetUint16(char* nvs_key, uint16_t* int_data){
    storageOpen();
    esp_err_t err = nvs_set_u16(storageHandler, nvs_key, *int_data);
    storageCheckErrorAndCommit(err, storageHandler);
    ESP_LOGI(TAG_STORAGE,"%s(w) %d", nvs_key, *int_data);
}


/**
 * @brief Realiza o processo de leitura na NVS para uma variável do tipo uint8
 * 
 * @note Caso o dado buscado na partição de storage não seja encontrado, é lido o
 * valor da variável correspondente dentro das configurações de fábrica
 * 
 * @param nvs_key label que define o local em que o dado deve ser buscado 
 * @param int_data valor que foi encontrada dentro da NVS
 * @retval None
 */
void storageGetUint8(char* nvs_key, uint8_t* int_data){
    storageOpen();
    esp_err_t err = nvs_get_u8(storageHandler, nvs_key, int_data);
    if(err != ESP_OK){
        ESP_LOGE(TAG_STORAGE, "Erro ao recuperar o uint8 %s da NVS: %s", nvs_key, esp_err_to_name(err));
        storageCloseHandler();
        return;
    }
    storageCloseHandler();
    ESP_LOGI(TAG_STORAGE,"%s(r) %u", nvs_key, *int_data);
}

/**
 * @brief Realiza o processo de escrita na NVS para uma variável do tipo uint8
 * 
 * @param nvs_key label que define o local em que o dado deve ser salvo na NVS
 * @param int_data valor que será salvo na NVS
 * @retval None
 */
void storageSetUint8(char* nvs_key, uint8_t* int_data){
    storageOpen();
    esp_err_t err = nvs_set_u8(storageHandler, nvs_key, *int_data);
    storageCheckErrorAndCommit(err, storageHandler);
    ESP_LOGI(TAG_STORAGE,"%s(w) %u", nvs_key, *int_data);
}

/**
 * @brief Realiza o processo de escrita na NVS para uma variável do tipo string 
 * 
 * @param storageHandler handler da NVS 
 * @param nvs_key label que define o local em que o dado deve ser salvo na NVS 
 * @param data string que será salva na NVS 
 * @retval None
 */
void storageSetString(char* nvs_key, char* data){
    storageOpen();
    esp_err_t err;
    err = nvs_set_str(storageHandler,nvs_key,data);
    storageCheckErrorAndCommit(err, storageHandler);
    ESP_LOGI(TAG_STORAGE,"%s(w) %s", nvs_key, data);
}

/**
 * @brief  Realiza o processo de leitura na NVS para uma variável do tipo string
 * 
 * @note Caso o dado buscado na partição de storage não seja encontrado, é lido o
 * valor da variável correspondente dentro das configurações de fábrica
 * 
 * @param storageHandler handler da NVS 
 * @param nvs_key label que define o local em que o dado deve ser buscado 
 * @param data string que foi encontrada dentro da NVS 
 * @retval None
 */
void storageGetString(char* nvs_key, char* data){
    storageOpen();
    size_t required_size;
    esp_err_t err = nvs_get_str(storageHandler,nvs_key,NULL,&required_size);

    if (err != ESP_OK) {
        ESP_LOGE("NVS", "Erro ao recuperar o blob %s da NVS: %s", nvs_key, esp_err_to_name(err));
        storageCloseHandler();
        return;
    }

    char* temp_data = (char*)malloc(required_size);
    if (temp_data == NULL) {
        ESP_LOGE("NVS", "Falha ao alocar memória para a string");
        storageCloseHandler();
        return;
    }

    err = nvs_get_str(storageHandler, nvs_key, temp_data, &required_size);
    if (err != ESP_OK) {
        ESP_LOGE("NVS", "Erro ao recuperar o blob %s da NVS: %s", nvs_key, esp_err_to_name(err));
        free(temp_data);
        storageCloseHandler();
        return;
    }

    strcpy(data, temp_data);

    free(temp_data);

    ESP_LOGI(TAG_STORAGE,"%s(r) %s", nvs_key, data);
    storageCloseHandler();
}

/**
 * @brief Realiza o processo de escrita na NVS para uma variável do tipo genérica, comumento umaa struct
 * 
 * @param nvs_key label que define o local em que o dado deve ser salvo na NVS 
 * @param data ponteiro para a variável desejada, onde será armazenado os valores encontrados
 * @param size ponteiro para o sizeof da variável desejada
 * @retval None
 */
esp_err_t storageSetBlob(const char *nvs_key, const void *data, size_t size) {
    esp_err_t err;
    storageOpen();

    //if (xSemaphoreTake(mutex_storage_blob, portMAX_DELAY) == pdTRUE) {
        err = nvs_set_blob(storageHandler, nvs_key, data, size);
        if (err != ESP_OK) {
            ESP_LOGE("NVS", "Erro ao armazenar o blob %s na NVS: %s", nvs_key, esp_err_to_name(err));
            storageCloseHandler();
            return err;
        }
        storageCheckErrorAndCommit(err, storageHandler);

    //    xSemaphoreGive(mutex_storage_blob);
    //}
    //else {
    //    ESP_LOGE(TAG_DEVICE, "Failed to take mutex storage blob");
    //}

    ESP_LOGI("NVS", "Blob %s armazenado na NVS com sucesso", nvs_key);
    return ESP_OK;
}

/**
 * @brief Realiza o processo de leitura na NVS para uma variável genérica, comumente uma struct
 * 
 * @note Caso o dado buscado na partição de storage não seja encontrado, é retornado err ao chamador
 * 
 * @param nvs_key label que define o local em que o dado deve ser buscado 
 * @param data ponteiro para a variável desejada, onde será armazenado os valores encontrados
 * @param size ponteiro para o sizeof da variável desejada
 * @retval None
 */
esp_err_t storageGetBlob(const char *nvs_key, void *data, size_t *size) {
    esp_err_t err;
    storageOpen();

    err = nvs_get_blob(storageHandler, nvs_key, data, size);
    if (err != ESP_OK) {
        ESP_LOGE("NVS", "Erro ao recuperar o blob %s da NVS: %s", nvs_key, esp_err_to_name(err));
        storageCloseHandler();
        return err;
    }

    storageCloseHandler();

    ESP_LOGI("NVS", "Blob %s recuperado da NVS com sucesso", nvs_key);
    return ESP_OK;
}

/**
 * @brief Inicializa o módulo NVS para armazenamento
 * 
 * @param  None
 * @retval None
 */
void storageInit(void){
    ESP_LOGI(TAG_STORAGE, "Initializing...");
    
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    mutex_storage_blob = xSemaphoreCreateMutex();

    if(mutex_storage_blob == NULL){
        ESP_LOGE(TAG_DEVICE, "Failed to create mutex storage blob");
    }
}