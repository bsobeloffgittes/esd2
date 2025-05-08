#include "wifi_control.h"
#include "global.h"


const char* ssid = "Device-Northwestern";


// === WebSocket Setup ===
const char* server_ip = "10.105.50.169"; // Replace with your PC's local IP
const uint16_t server_port = 8888;
const char* ws_path = "/ws_esp32";

WebSocketsClient webSocket;


void webSocketEvent(WStype_t type, uint8_t* payload, size_t length) {
    switch (type) {
        case WStype_CONNECTED:
        Serial.println("[WebSocket] Connected");
        break;
        case WStype_DISCONNECTED:
        Serial.println("[WebSocket] Disconnected");
        break;
        case WStype_TEXT:
        Serial.printf("[WebSocket] Message from server: %s\n", payload);
        break;
        default:
        break;
    }
}
  
void wifi_init(void) {
    Serial.begin(115200);
    delay(1000);
    Serial.println("Booting...");
    Serial.println("ESP32 Wifi MAC Address:");
    Serial.println(WiFi.macAddress());


    Serial.println("Booting...");


    // Connect to Wi-Fi
    WiFi.begin(ssid);
    Serial.println("Booting...");
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWi-Fi connected, IP: " + WiFi.localIP().toString());

    // Start WebSocket connection
    webSocket.begin(server_ip, server_port, ws_path);
    webSocket.onEvent(webSocketEvent);
    webSocket.setReconnectInterval(2000);

    Serial.println("Connecting to WebSocket at: " + String(server_ip));
}

void service_websocket(void) {
    int32_t count = encoder.getCount();
    // Serial.println("Encoder count = " + String(count));

    // Send encoder count over WebSocket
    if (webSocket.isConnected()) {
      String msg = String("{\"encoder\":") + count + "}";
      webSocket.sendTXT(msg);
    }

    webSocket.loop();
}