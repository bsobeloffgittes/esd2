#pragma once

#include <Adafruit_ICM20X.h>
#include <Adafruit_ICM20948.h>
#include <Adafruit_Sensor.h>
#include <ESP32Encoder.h>
//#include <ESP32_Servo.h>


#define SERVO_PIN 18

#define ENCODER1_A 25
#define ENCODER1_B 26

#define ENCODER2_A 27
#define ENCODER2_B 14


extern Adafruit_ICM20948 icm;
extern sensors_event_t accel;
extern sensors_event_t gyro;
extern sensors_event_t mag;
extern sensors_event_t temp;


//extern Servo steering_servo;
extern int steering_angle;


extern bool motor_enabled;
extern float motor1_power_ref;
extern float motor2_power_ref;

extern float motor1_power_actual;
extern float motor2_power_actual;

extern bool direction_forward;

extern int encoder1_counts;
extern int encoder2_counts;

extern float encoder1_rpm;
extern float encoder2_rpm;
