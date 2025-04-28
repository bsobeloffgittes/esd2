#ifndef IMU_H_
#define IMU_H_



#include <Adafruit_ICM20X.h>
#include <Adafruit_ICM20948.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

void imu_setup(Adafruit_ICM20948 & icm);


#endif