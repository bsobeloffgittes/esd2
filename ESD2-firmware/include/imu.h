#pragma once


#include <Adafruit_ICM20X.h>
#include <Adafruit_ICM20948.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "global.h"

void imu_setup(void);

// void read_imu(Adafruit_ICM20948 & icm, sensors_event_t & accel, sensors_event_t & gyro, sensors_event_t & mag, sensors_event_t & temp);
void read_imu(void);
void print_imu(void);
