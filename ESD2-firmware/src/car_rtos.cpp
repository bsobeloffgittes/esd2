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
        set_motor1_power(motor1_power_actual);
        set_motor2_power(motor2_power_actual);

        // Serial.println("Encoder count = " + String(encoder_counts));

        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
    
}

void sense_task(void * params) {
    Encoder encoder1;
    Encoder encoder2;

    // setup_encoder();
    // Enable the weak pull up resistors
    // pinMode(ENCODER1_A, INPUT);
    // pinMode(ENCODER1_B, INPUT);
	ESP32Encoder::useInternalWeakPullResistors = puType::up;

	// use pin 19 and 18 for the first encoder
	encoder1.initialize(ENCODER1_A, ENCODER1_B);
    encoder2.initialize(ENCODER2_A, ENCODER2_B);
    
	// // set starting count value after attaching
	// encoder1.setCount(0);
    // encoder2.setCount(0);
    

    imu_setup();

    while(true) {
        read_imu();

        // Read and send encoder data
        //encoder_counts = encoder.getCount();
        encoder1_rpm = encoder1.get_rpm();
        encoder2_rpm = encoder2.get_rpm();

        Serial.println("encoder1: " + String(encoder1_rpm) + " encoder2: " + String(encoder2_rpm));

        run_wheel_pid(encoder1_rpm, encoder2_rpm);

        vTaskDelay(10 / portTICK_PERIOD_MS);

        
    }

}


