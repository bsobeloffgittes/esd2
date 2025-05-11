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
    int pos = 0;    // variable to store the servo position
   while(true) {
    vTaskDelay(15 / portTICK_PERIOD_MS);
    steering_servo.write(steering_angle);

    
   }
}

void dc_motor_control_task(void * params) {
    Serial.print("in speed_control");
    setup_motor1();
    setup_motor2();
    setup_encoder();

    bool motor_enabled = false;
    bool direction_forward = true;  // true = forward, false = reverse
    while(true) {
        set_motor1_power(motor_power);
        set_motor2_power(motor_power);
        Serial.print(motor_power);
        vTaskDelay(15 / portTICK_PERIOD_MS);

        // Read and send encoder data
        encoder_counts = encoder.getCount();
        Serial.println("Encoder count = " + String(encoder_counts));

        
    }
    


}
