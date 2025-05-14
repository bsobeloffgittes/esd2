#pragma once

#include "global.h"
#include "dc_motor.h"
#include "imu.h"
#include "wifi_control.h"
#include "servo.h"

void wifi_task(void * params);
void speed_control_task(void * params);
void dc_motor_control_task(void * params);


