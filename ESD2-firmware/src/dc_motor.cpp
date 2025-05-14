#include "dc_motor.h"

void setup_motor1() {
    pinMode(MOTOR_IN2_PIN, OUTPUT);
    pinMode(MOTOR_IN1_PIN, OUTPUT);

    // Set up PWM on PWMA 
    ledcSetup(0, 1000, 8);
    ledcAttachPin(MOTOR_PWMA_PIN,0);
}

// Take in power from 0-1
void set_motor1_power(float power) {
    if(power >= 0) {
        digitalWrite(MOTOR_IN1_PIN, HIGH);
        digitalWrite(MOTOR_IN2_PIN, LOW);
        } else {
        digitalWrite(MOTOR_IN1_PIN, LOW);
        digitalWrite(MOTOR_IN2_PIN, HIGH);
        power = power * -1; // make it positive for next step
    }

    uint8_t power_int = (uint8_t) (power * 255);

    ledcWrite(0, power_int);
    //analogWrite(MOTOR_EN_PIN, power_int);
}

void setup_motor2() {
    pinMode(MOTOR2_IN2_PIN, OUTPUT);
    pinMode(MOTOR2_IN1_PIN, OUTPUT);

    // Set up PWM on PWMB 
    ledcSetup(1, 1000, 8); // Channel 1 for motor 2
    ledcAttachPin(MOTOR2_PWMB_PIN,1);
}

// Take in power from 0-1
void set_motor2_power(float power) {
    if(power >= 0) {
        digitalWrite(MOTOR2_IN1_PIN, HIGH);
        digitalWrite(MOTOR2_IN2_PIN, LOW);
        } else {
        digitalWrite(MOTOR2_IN1_PIN, LOW);
        digitalWrite(MOTOR2_IN2_PIN, HIGH);
        power = power * -1; // make it positive for next step
    }

    uint8_t power_int = (uint8_t) (power * 255);

    ledcWrite(1, power_int);
    //analogWrite(MOTOR_EN_PIN, power_int);
}

// void setup_encoder() {
//       // Enable the weak pull up resistors
// 	ESP32Encoder::useInternalWeakPullResistors = puType::up;

// 	// use pin 19 and 18 for the first encoder
// 	encoder.attachHalfQuad(ENCODER1_A, ENCODER1_B);
    
// 	// set starting count value after attaching
// 	encoder.setCount(0);
// }

