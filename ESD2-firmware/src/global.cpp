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
bool direction_forward;

int encoder1_counts;
int encoder2_counts;
