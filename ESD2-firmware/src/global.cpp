#include "global.h"

Adafruit_ICM20948 icm;

sensors_event_t accel;
sensors_event_t gyro;
sensors_event_t mag;
sensors_event_t temp;


// Servo steering_servo;
int steering_angle;


bool motor_enabled;
float motor_power;


float motor1_power_ref;
float motor2_power_ref;

float motor1_power_actual;
float motor2_power_actual;

bool direction_forward;

int encoder1_counts;
int encoder2_counts;

float encoder1_rpm;
float encoder2_rpm;