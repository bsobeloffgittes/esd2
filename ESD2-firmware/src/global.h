#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <Adafruit_ICM20X.h>
#include <Adafruit_ICM20948.h>
#include <Adafruit_Sensor.h>
#include <ESP32Encoder.h>
#include <ESP32_Servo.h>


#define SERVO_PIN 18


extern Adafruit_ICM20948 icm;
extern sensors_event_t accel;
extern sensors_event_t gyro;
extern sensors_event_t mag;
extern sensors_event_t temp;


extern ESP32Encoder encoder;

extern Servo steering_servo;


extern bool motor_enabled;
extern bool direction_forward;

#endif