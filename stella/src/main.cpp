#include <Arduino.h>
#include <ESP32_Servo.h>

#include "global.h"
#include "imu.h"
#include "dc_motor.h"
#include <WiFi.h>
#include <WebSocketsClient.h>

// Wifi Setup
const char* ssid = "Device-Northwestern";
// const char* password = "YOUR_WIFI_PASSWORD";

// === WebSocket Setup ===
const char* server_ip = "10.105.50.169"; // Replace with your PC's local IP
const uint16_t server_port = 8888;
const char* ws_path = "/ws_esp32";

// ESP32Encoder encoder;
// ESP32Encoder encoder2;

// // timer and flag for example, not needed for encoders
// unsigned long encoder2lastToggled;
// bool encoder2Paused = false;






//uint16_t measurement_delay_us = 65535;



#define SERVO_PIN 18

int pos = 0;    // variable to store the servo position

Servo steering_servo;

// === WebSocket Client ===
WebSocketsClient webSocket;

// === WebSocket Event Callback ===
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

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Booting...");
  Serial.println("ESP32 Wifi MAC Address:");
  Serial.println(WiFi.macAddress());

  Wire.begin();
  steering_servo.attach(SERVO_PIN);
  Serial.println("Booting...");


  setup_dc();
  setup_encoder();
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


  imu_setup();
}

void loop() {
  float motor_power;

  // Sweep servo forward
  for (pos = 0; pos <= 180; pos++) {
    steering_servo.write(pos);
    delay(15);
    set_motor_power(((float)(pos - 90)) / 90);
    read_imu();

    int32_t count = encoder.getCount();
    // Serial.println("Encoder count = " + String(count));

    // Send encoder count over WebSocket
    if (webSocket.isConnected()) {
      String msg = String("{\"encoder\":") + count + "}";
      webSocket.sendTXT(msg);
    }

    webSocket.loop();
  }

  // Sweep servo backward
  for (pos = 180; pos >= 0; pos--) {
    steering_servo.write(pos);
    delay(15);
    set_motor_power(((float)(pos - 90)) / 90);
    read_imu();

    int32_t count = encoder.getCount();
    // Serial.println("Encoder count = " + String(count));

    // Send encoder count over WebSocket
    if (webSocket.isConnected()) {
      String msg = String("{\"encoder\":") + count + "}";
      webSocket.sendTXT(msg);
    }

    webSocket.loop();
  }

  delay(100);
}