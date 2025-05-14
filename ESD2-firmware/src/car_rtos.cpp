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

    int pos = 0;    // variable to store the servo position

    //steering_servo.attach(SERVO_PIN);
    init_servo();

    imu_setup();
    // delay(100);

    vTaskDelay(500 / portTICK_PERIOD_MS);

    while(true) {
        set_servo_angle(steering_angle);
        // steering_servo.write(steering_angle);
        // Serial.println(motor_power);

        // set_motor1_power(motor_power);
        // set_motor2_power(motor_power);

        // encoder_counts = encoder.getCount();

        read_imu();

        vTaskDelay(5 / portTICK_PERIOD_MS);


   }
}

void dc_motor_control_task(void * params) {
    setup_motor1();
    setup_motor2();
    setup_encoder();

    motor_enabled = false;
    direction_forward = true;  // true = forward, false = reverse

    vTaskDelay(100 / portTICK_PERIOD_MS);

    while(true) {
        Serial.print("dc motor loop");
        set_motor1_power(motor_power);
        set_motor2_power(motor_power);
        // set_motor2_power(motor_power);
        // Serial.print(motor_power);
        

        // Read and send encoder data
        encoder_counts = encoder.getCount();
        // Serial.println("Encoder count = " + String(encoder_counts));

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
    


}
