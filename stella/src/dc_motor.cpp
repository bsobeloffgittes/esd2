#include "dc_motor.h"

void setup_dc() {
    pinMode(MOTOR_IN2_PIN, OUTPUT);
    pinMode(MOTOR_IN1_PIN, OUTPUT);

    // Set up PWM on PWMA 
    ledcSetup(0, 1000, 8);
    ledcAttachPin(MOTOR_PWMA_PIN,0);
}

// Take in power from 0-1
void set_motor_power(float power) {
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


void setup_encoder() {
      // Enable the weak pull up resistors
	ESP32Encoder::useInternalWeakPullResistors = puType::up;

	// use pin 19 and 18 for the first encoder
	encoder.attachHalfQuad(25, 26);
    
	// set starting count value after attaching
	encoder.setCount(0);
}


int get_encoder_counts() {

}