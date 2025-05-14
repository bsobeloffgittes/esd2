#pragma once

#include <Arduino.h>
#include <ESP32Encoder.h>
#include "global.h"


#define SERVO_PWM_CHANNEL 5

void init_servo(void);

void set_servo_angle(uint8_t angle);