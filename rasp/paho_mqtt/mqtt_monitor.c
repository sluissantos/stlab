#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include "MQTTClient.h"

#define ADDRESS     "tcp://gw.qa.revolog.com.br:1883"   // Endereço do broker MQTT
#define CLIENTID    "RaspberryPiClient"                 // ID do cliente MQTT
#define TOPIC       "stlab/#"                           // Tópico a ser monitorado
#define QOS         1
#define TIMEOUT     10000L
#define FILENAME    "mensagens_mqtt.txt"                // Nome do arquivo para salvar as mensagens
#define USERNAME    "tecnologia"                        // Usuário MQTT
#define PASSWORD    "128Parsecs!"                       // Senha MQTT

volatile int finished = 0;

int messageArrivedCallback(void *context, char *topicName, int topicLen, MQTTClient_message *message) {
    struct timeval tv;
    struct tm *tm_info;
    char buffer[64];

    gettimeofday(&tv, NULL);
    tm_info = localtime(&tv.tv_sec);

    // Formatar a data e hora
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);

    if (message->payloadlen > 0) {
        char *payload = (char *)message->payload;
        int is_valid = 1;

        printf("Tópico: %s\n", topicName);

        for (int i = 0; i < message->payloadlen; i++) {
            if (payload[i] < 32 || payload[i] > 126) {
                is_valid = 0;
                break;
            }
        }

        if (is_valid) {
            FILE *file = fopen(FILENAME, "a");
            if (file) {
                fprintf(file, "Tópico: %s Mensagem: %.*s Time: %ld.%06ld Date: %s\n",
                        topicName, message->payloadlen, payload,
                        tv.tv_sec, tv.tv_usec, buffer);
                fclose(file);
            }
            printf("Mensagem recebida e salva no arquivo: %.*s Time: %ld.%06ld Date: %s\n",
                   message->payloadlen, payload, tv.tv_sec, tv.tv_usec, buffer);
        } else {
            printf("Mensagem inválida ignorada.\n");
        }
    }

    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);

    return 1; // Indica sucesso no processamento
}

void connectionLostCallback(void *context, char *cause) {
    fprintf(stderr, "Conexão perdida: %s\n", cause);
    finished = 1;
}

int main(int argc, char *argv[]) {
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    int rc;

    // Inicializar o cliente MQTT
    MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    MQTTClient_setCallbacks(client, NULL, connectionLostCallback, messageArrivedCallback, NULL);

    // Configurar credenciais de autenticação
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    conn_opts.username = USERNAME;
    conn_opts.password = PASSWORD;

    // Conectar ao broker MQTT
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS) {
        fprintf(stderr, "Falha ao conectar, código de retorno: %d\n", rc);
        exit(EXIT_FAILURE);
    }

    printf("Conectado ao broker MQTT em %s\n", ADDRESS);

    // Inscrever-se no tópico
    if ((rc = MQTTClient_subscribe(client, TOPIC, QOS)) != MQTTCLIENT_SUCCESS) {
        fprintf(stderr, "Falha ao se inscrever no tópico, código de retorno: %d\n", rc);
        exit(EXIT_FAILURE);
    }

    printf("Monitorando o tópico: %s\n", TOPIC);

    // Loop principal
    while (!finished) {
        usleep(100000L); // Pequena pausa para evitar uso intensivo de CPU
    }

    // Limpar recursos
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);

    return 0;
}
