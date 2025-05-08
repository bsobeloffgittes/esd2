#ifndef WIFI_CONTROL_H_
#define WIFI_CONTROL_H_

#include <WiFi.h>
#include <WebSocketsClient.h>


extern const char* ssid;

extern const char* server_ip;
extern const uint16_t server_port;
extern const char* ws_path;

extern WebSocketsClient webSocket;


void webSocketEvent(WStype_t type, uint8_t* payload, size_t length);

void wifi_init(void);

void service_websocket(void);


#endif