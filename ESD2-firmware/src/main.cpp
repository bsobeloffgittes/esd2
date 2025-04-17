#include <Arduino.h>
#include <ESP32_Servo.h>

// put function declarations here:
int myFunction(int, int);

#define SERVO_PIN 18

Servo steering_servo;

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}