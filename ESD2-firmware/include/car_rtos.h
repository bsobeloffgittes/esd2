#pragma once

#include "global.h"
#include "dc_motor.h"
#include "imu.h"
#include "wifi_control.h"
#include "servo.h"
#include "encoder.h"

void wifi_task(void * params);
void servo_control_task(void * params);
void dc_motor_control_task(void * params);
void sense_task(void * params);


