/**
 * @file devices_mian.c
 * @author Luis Santos (luis.santos@logpyx.com)
 * @author Henrique Ferreira (henrique.ferreira@logpyx.com)
 * @brief Trata funções relacionadas aos devices (periféricos), gerenciamento de conexão,configuração e informações sobre;;  
 * 
 * @version 2.0.0
 * @date 2024-03
 * 
 * @attention
 * 
 * <h2><center>&copy; COPYRIGHT 2023 LogPyx S/A</center></h2>
 * 
 */

#include "devices_headers.h"
#include "storage_headers.h"

device_t deviceList[DEVICE_QNT] = {DEVICE_DEFAULT(),
                                    DEVICE_DEFAULT(),
                                    DEVICE_DEFAULT(),
                                    DEVICE_DEFAULT()};

uint8_t inConnectionProcess =0;

int8_t indxCelular = -1;

/*
* Função: deviceCheckConnectionTask();
* Descrição: Rotina para verificar se existe algum device desconectado. 
* Se algum dispositvo encontra se desconectado, é realizado uma tentativa de conexão.
* Argumentos: void
* Retorno:    void 
*/
void deviceConnectionTask(void * pvParameter){
	static uint8_t deviceIndx=0;
	uint8_t count=19; 
	//  uint16_t dist[]={100,200,300,400, 500, 600, 700, 800, 900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,
	// 1900,1800,1700,1600,1500,1400,1300,1200,1100,1000,900,800,700,600,500,400,300,200,100};
	const TickType_t xDelay = DEVICE_TASK_DELAY / portTICK_PERIOD_MS;
	while(1){
        if(deviceList[deviceIndx].status == DEVICE_STATUS_WAIT_FOR_CONECTING){
                // Testa se o dispositivo esta conectado
                deviceConnect(deviceIndx);
                
        }else{
            if((deviceList[deviceIndx].status == DEVICE_STATUS_CONNECTING) &
                (deviceList[deviceIndx].timeout >= DEVICE_TIMEOUT_LIMITE) ){
                    deviceList[deviceIndx].status = DEVICE_STATUS_WAIT_FOR_CONECTING;
                }
        }
        deviceIndx++;
        //deviceIndx = deviceIndx%(DEVICE_QNT-1);
        // ESP_LOGI("DeviceTask","DeviceIndx: %d",deviceIndx);
        
        
        // dataManagerPickPlaceEngine(dist[count]);
        count++;
        count=count%39;

        //size_t free_heap_size = heap_caps_get_free_size(MALLOC_CAP_8BIT);
        //size_t largest_free_block = heap_caps_get_largest_free_block(MALLOC_CAP_8BIT);
        //ESP_LOGI("HEAP:", "Free Heap Size: %u bytes, Largest Free Memory Block: %u bytes", free_heap_size, largest_free_block);

        vTaskDelay(xDelay);
    }
}

   
/*
// Função: deviceConnect(uint8_t deviceIndx);
// Descrição: Conecta um dispositivo caso exista um link disponível no BLE serve.
// Argumentos: uint8_t deviceIndx -> DEVICE_UART_INDX
//                                   DEVICE_BLE1_INDX
//                                   DEVICE_BLE2_INDX
//                                   DEVICE_BLE3_INDX
// Retorno:    int8_t gattsConnectionID -> 0 a 2 conexões válidas
//                                        -1     sem conexões 
*/
#define TEMPO 61
int8_t deviceConnect(uint8_t deviceIndx){
    static uint8_t toogle=0;
    static uint16_t localTimer=0;
    int8_t connAvailable =-1;
    uint8_t data[1] = {deviceIndx};
    // ESP_LOGI("DeviceConn","DeviceIndx: %d GATTS_CONN: %d Interface: %d",deviceIndx,deviceList[deviceIndx].gattsConnectionID,deviceList[deviceIndx].interface);
   	switch (deviceList[deviceIndx].interface){
        case COMM_INTERFACE_UART:
            //commSendCommand(deviceList[deviceIndx],RD_REQUEST_CONNECTION,data,2);
        break;

        default:
        break;
                   
   }
      //deviceRotinaLed();
    /*  bleuartClientRequestTemp(0);

      localTimer++;
      localTimer = localTimer%TEMPO;

      if(localTimer == 0 ){
        bleuartClientOnOffCamera(0,1);
      }

      if(localTimer == 20){
         bleuartClientOnOffCamera(1,1);
      }*/
      

    return deviceList[deviceIndx].gattsConnectionID;
}

/*
// Função: deviceDisconnect(uint8_t deviceIndx);
// Descrição: Função responsável por disconectar dispositivo
// Argumentos: uint8_t deviceIndx -> DEVICE_BLE1_INDX
//                                   DEVICE_BLE2_INDX
//                                   DEVICE_BLE3_INDX
// Retorno:    int8_t deviceIndx ->  
// Obs: Função tem apenas efeito a dispositivos conectados via bluetooth
*/
int8_t deviceDisconnect(uint8_t deviceIndx){
	uint8_t connId[1]  ={deviceIndx};
	//commSendCommand(deviceList[deviceIndx],RD_REQUEST_DISCONNECTION,&connId[0],2);
	ESP_LOGI("DEVICE_BLE","DISCONECTD: %d",deviceIndx);
	return deviceIndx;
}

/*
// Função: deviceGet(uint8_t deviceIndx);
// Descrição: Retorna uma struct contendo os dados sobre disposito. 
// Argumentos: uint8_t deviceIndx -> DEVICE_UART_INDX
//                                   DEVICE_BLE1_INDX
//                                   DEVICE_BLE2_INDX
//                                   DEVICE_BLE3_INDX
//             
// Retorno:    device_t -> Struct contendo dados do device
*/
device_t * deviceGet(uint8_t deviceIndx){
  	return &deviceList[deviceIndx];
}

/*
// Função: deviceGetCelular();
// Descrição: Retorna o device que carrega conexão do celular 
// Argumentos:              
// Retorno:    device_t -> Struct contendo dados do device
*/
device_t * deviceGetCelular(){
  	return &deviceList[indxCelular];
}

/*
// Função: deviceSetIndxCelular();
// Descrição: Retorna o device que carrega conexão do celular 
// Argumentos:              
// Retorno:    device_t -> Struct contendo dados do device
*/
void deviceSetIndxCelular(int8_t index){
    indxCelular = index;
}

/*
// Função: deviceGetIndxCelular();
// Descrição: Retorna o indeice device que carrega conexão do celular 
// Argumentos:              
// Retorno:    uint8_t -> Struct contendo dados do device
*/
uint8_t deviceGetIndxCelular(){
   return indxCelular;
}