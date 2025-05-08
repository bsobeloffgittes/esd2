#ifndef CAR_RTOS_H_
#define CAR_RTOS_H_

#include "global.h"
#include "dc_motor.h"
#include "imu.h"
#include "wifi_control.h"

void wifi_task(void * params);
void speed_control_task(void * params);


#endif