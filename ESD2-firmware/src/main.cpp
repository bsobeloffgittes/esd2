#include <Arduino.h>
#include <ESP32_Servo.h>

#include "glob.h"
#include "imu.h"


uint16_t measurement_delay_us = 65535;


Adafruit_ICM20948 icm;


#define SERVO_PIN 18

int pos = 0;    // variable to store the servo position

Servo steering_servo;

void setup() {

  // Wire.setPins(sda_pin, scl_pin);
  Wire.begin();


  // put your setup code here, to run once:
  steering_servo.attach(SERVO_PIN); 







  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  imu_setup(icm);
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












   //  /* Get a new normalized sensor event */
   sensors_event_t accel;
   sensors_event_t gyro;
   sensors_event_t mag;
   sensors_event_t temp;
   icm.getEvent(&accel, &gyro, &temp, &mag);
 
   Serial.print("\t\tTemperature ");
   Serial.print(temp.temperature);
   Serial.println(" deg C");
 
   /* Display the results (acceleration is measured in m/s^2) */
   Serial.print("\t\tAccel X: ");
   Serial.print(accel.acceleration.x);
   Serial.print(" \tY: ");
   Serial.print(accel.acceleration.y);
   Serial.print(" \tZ: ");
   Serial.print(accel.acceleration.z);
   Serial.println(" m/s^2 ");
 
   Serial.print("\t\tMag X: ");
   Serial.print(mag.magnetic.x);
   Serial.print(" \tY: ");
   Serial.print(mag.magnetic.y);
   Serial.print(" \tZ: ");
   Serial.print(mag.magnetic.z);
   Serial.println(" uT");
 
   /* Display the results (acceleration is measured in m/s^2) */
   Serial.print("\t\tGyro X: ");
   Serial.print(gyro.gyro.x);
   Serial.print(" \tY: ");
   Serial.print(gyro.gyro.y);
   Serial.print(" \tZ: ");
   Serial.print(gyro.gyro.z);
   Serial.println(" radians/s ");
   Serial.println();
 
   delay(100);
}


