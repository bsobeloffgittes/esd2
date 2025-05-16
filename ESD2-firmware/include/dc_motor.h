#pragma once

#include <Arduino.h>
#include <ESP32Encoder.h>
#include "global.h"

#define MOTOR_IN2_PIN 33 // AIN2
#define MOTOR_IN1_PIN 32 // AIN1
#define MOTOR_PWMA_PIN 19

#define MOTOR2_IN1_PIN 12 // BI1
#define MOTOR2_IN2_PIN 13 // BI2
#define MOTOR2_PWMB_PIN 5



#define ENCODER_A_PIN 27
#define ENCODER_B_PIN 14

void setup_motor1(void);
void set_motor1_power(float power);

void setup_motor2(void);
void set_motor2_power(float power);

int get_encoder_counts(void);

void run_wheel_pid(float rpm1, float rpm2);

