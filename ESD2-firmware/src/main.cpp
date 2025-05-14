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
    servo_control_task,	// Function to be called
    "servo_control_task",	// Name of task
    4096,				// Stack size in bytes
    NULL,				// Parameter to pass to function (void*)
    3,					// Task priority (0 to configMAX_PRIORITIES - 1)
    NULL				// Task handle (TaskHandle_t*)
  );

  xTaskCreate(
    dc_motor_control_task,
    "dc motor control task",
    2048,
    NULL,
    2,
    NULL
  );

  xTaskCreate(
    sense_task,
    "sense task",
    4096,
    NULL,
    0,
    NULL
  );
  
  vTaskDelete(NULL);


}

void loop() {

  // not used
}


