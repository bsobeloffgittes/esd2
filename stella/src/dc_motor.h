#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include <Arduino.h>
#include <ESP32Encoder.h>
#include "global.h"

#define MOTOR_IN2_PIN 33 // AIN2
#define MOTOR_IN1_PIN 32 // AIN1
#define MOTOR_PWMA_PIN 19

#define ENCODER_A_PIN 25
#define ENCODER_B_PIN 26

void setup_dc(void);
void set_motor_power(float power);

void setup_encoder(void);

int get_encoder_counts(void);


#endif