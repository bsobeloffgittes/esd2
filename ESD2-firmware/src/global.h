#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <Adafruit_ICM20X.h>
#include <Adafruit_ICM20948.h>
#include <Adafruit_Sensor.h>

extern Adafruit_ICM20948 icm;
extern sensors_event_t accel;
extern sensors_event_t gyro;
extern sensors_event_t mag;
extern sensors_event_t temp;

#endif