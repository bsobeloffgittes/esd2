#include "wifi_control.h"
#include "global.h"
#include "dc_motor.h"


const char* ssid = "Device-Northwestern";


// === WebSocket Setup ===
// TODO: make this not have a problem with different computers
const char* server_ip = "10.105.13.187"; // 10.105.13.187 for Benji, 10.105.42.206 for Stella
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
        if (strcmp((char*)payload, "start_motor") == 0) {
            motor_enabled = true;
            webSocket.sendTXT("motor_started");
        } else if (strcmp((char*)payload, "stop_motor") == 0) {
            motor_enabled = false;
            set_motor1_power(0);
            webSocket.sendTXT("motor_stopped");
        } else if (strcmp((char*)payload, "set_direction:forward") == 0) {
            direction_forward = true;
        } else if (strcmp((char*)payload, "set_direction:reverse") == 0) {
            direction_forward = false;
        } else if (strncmp((char*)payload, "servo:", 6) == 0) {
            int angle = atoi((char*)payload + 6);  // Get number after "servo:"
            Serial.println(angle);
            angle = constrain(angle, 0, 180);      // Keep within range
            steering_angle = angle;
            Serial.println(angle);
            Serial.println("Servo set to angle: " + String(angle));
        }
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

    Wire.begin();
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
    // Keep WebSocket connection alive
  webSocket.loop();

  if (motor_enabled) {
      // Set motor power based on direction
      float power = 1.0;

      if (!direction_forward) {
          power = -1.0;
      }

      motor_power = power;
      
    } 
      else {
      motor_power = 0;
    }

    if (webSocket.isConnected()) {
        String msg = String("{\"encoder\":") + encoder1_counts + "acceleration: " + accel.acceleration.z +"}";
        webSocket.sendTXT(msg);
    }

}

