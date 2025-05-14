#include "car_rtos.h"

void wifi_task(void * params) {
    wifi_init();

    Serial.println("wifi init finished ---------------");

    while(true) {
        
        service_websocket();
        

        // Loop at 100 Hz
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}



void servo_control_task(void * params) {

    int pos = 0;    // variable to store the servo position

    init_servo();

    vTaskDelay(100 / portTICK_PERIOD_MS);

    while(true) {
        set_servo_angle(steering_angle);

        vTaskDelay(10 / portTICK_PERIOD_MS);


   }
}

void dc_motor_control_task(void * params) {
    setup_motor1();
    setup_motor2();

    motor_enabled = false;
    direction_forward = true;  // true = forward, false = reverse

    vTaskDelay(100 / portTICK_PERIOD_MS);

    while(true) {
        // Serial.print("dc motor loop");
        set_motor1_power(motor_power);
        set_motor2_power(motor_power);

        // Serial.println("Encoder count = " + String(encoder_counts));

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
    
}

void sense_task(void * params) {
    setup_encoder();

    imu_setup();

    while(true) {
        read_imu();

        // Read and send encoder data
        encoder_counts = encoder.getCount();
        Serial.print("encoder: ");
        Serial.println(encoder_counts);

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }

}
