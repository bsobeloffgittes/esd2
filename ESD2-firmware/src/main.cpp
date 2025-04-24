#include <Arduino.h>
#include <ESP32_Servo.h>


#define SERVO_PIN 18

int pos = 0;    // variable to store the servo position

Servo steering_servo;

void setup() {
  // put your setup code here, to run once:
  steering_servo.attach(SERVO_PIN); 
}

void loop() {
  // put your main code here, to run repeatedly:
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    steering_servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    steering_servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}


