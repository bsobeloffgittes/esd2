#include "dc_motor.h"

void setup_dc() {
    pinMode(MOTOR_EN_PIN, OUTPUT);
    pinMode(MOTOR_PH_PIN, OUTPUT);
}

// Take in power from 0-1
void set_motor_power(float power) {
    if(power >= 0) {
        digitalWrite(MOTOR_PH_PIN, HIGH);
    } else {
        digitalWrite(MOTOR_PH_PIN, LOW);
        power = power * -1; // make it positive for next step
    }

    uint8_t power_int = (uint8_t) (power * 255);

    analogWrite(MOTOR_EN_PIN, power_int);
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