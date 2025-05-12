#include <Arduino.h>

#include "global.h"
#include "imu.h"
#include "dc_motor.h"
#include "wifi_control.h"
#include "car_rtos.h"




void setup() {

  Serial.begin(115200);
  while (!Serial)
  delay(10); // will pause Zero, Leonardo, etc until serial console opens

  // Wire.setPins(sda_pin, scl_pin);
  Wire.begin();

  // put your setup code here, to run once:
  // steering_servo.attach(SERVO_PIN); 

  


  


  // Create a task and start it immediately
  xTaskCreatePinnedToCore(
    wifi_task,	// Function to be called
    "wifi task",	// Name of task
    4096,				// Stack size in bytes
    NULL,				// Parameter to pass to function (void*)
    1,					// Task priority (0 to configMAX_PRIORITIES - 1)
    NULL,				// Task handle (TaskHandle_t*)
    1
  );

  xTaskCreate(
    speed_control_task,	// Function to be called
    "speed_control_task",	// Name of task
    1024,				// Stack size in bytes
    NULL,				// Parameter to pass to function (void*)
    3,					// Task priority (0 to configMAX_PRIORITIES - 1)
    NULL				// Task handle (TaskHandle_t*)
  );

  // xTaskCreate(
  //   dc_motor_control_task,	// Function to be called
  //   "dc motor control task",	// Name of task
  //   2048,				// Stack size in bytes
  //   NULL,				// Parameter to pass to function (void*)
  //   2,					// Task priority (0 to configMAX_PRIORITIES - 1)
  //   NULL				// Task handle (TaskHandle_t*)
  // );
  
  vTaskDelete(NULL);


}

void loop() {

  // not used
}


