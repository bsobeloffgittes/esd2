#include <Arduino.h>
#include <ESP32_Servo.h>

#include "global.h"
#include "imu.h"
#include "dc_motor.h"


ESP32Encoder encoder;
// ESP32Encoder encoder2;

// // timer and flag for example, not needed for encoders
// unsigned long encoder2lastToggled;
// bool encoder2Paused = false;






//uint16_t measurement_delay_us = 65535;



#define SERVO_PIN 18

int pos = 0;    // variable to store the servo position

Servo steering_servo;

void setup() {

  // Wire.setPins(sda_pin, scl_pin);
  Wire.begin();


  // put your setup code here, to run once:
  steering_servo.attach(SERVO_PIN); 

  setup_dc();
  setup_encoder();







  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  imu_setup();
}

void loop() {

  float motor_power;
  // put your main code here, to run repeatedly:
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    steering_servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    set_motor_power(((float) (pos - 90))/90);
    read_imu();
    // print_imu();
    Serial.println("Encoder count = " + String((int32_t)encoder.getCount()));
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    steering_servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    set_motor_power(-1);
    set_motor_power(((float) (pos - 90))/90);
    read_imu();
    // print_imu();
    Serial.println("Encoder count = " + String((int32_t)encoder.getCount()));
  }


 
  delay(100);
}


