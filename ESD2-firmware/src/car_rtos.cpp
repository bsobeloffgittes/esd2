#include "car_rtos.h"

void wifi_task(void * params) {
    wifi_init();

    Serial.println("wifi init finished ---------------");

    while(true) {
        service_websocket();

        // Loop at 10 Hz
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}



void speed_control_task(void * params) {
    steering_servo.attach(SERVO_PIN); 
    float motor_power;
    int pos = 0;    // variable to store the servo position

    /*for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        steering_servo.write(pos);              // tell servo to go to position in variable 'pos'
        vTaskDelay(15 / portTICK_PERIOD_MS);                      // waits 15ms for the servo to reach the position
        set_motor_power(((float) (pos - 90))/90);
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        steering_servo.write(pos);              // tell servo to go to position in variable 'pos'
        vTaskDelay(15 / portTICK_PERIOD_MS);                         // waits 15ms for the servo to reach the position
        set_motor_power(((float) (pos - 90))/90);

        // Loop at 10 Hz
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }*/
   while(true) {
    // vTaskDelay(15 / portTICK_PERIOD_MS);
    // steering_servo.write(steering_angle);
    Serial.print("blah");
    // put your main code here, to run repeatedly:
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    steering_servo.write(pos);              // tell servo to go to position in variable 'pos'
    vTaskDelay(15/ portTICK_PERIOD_MS);                         // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    steering_servo.write(pos);              // tell servo to go to position in variable 'pos'
    vTaskDelay(15/ portTICK_PERIOD_MS);                      // waits 15ms for the servo to reach the position
  }
   }
}
