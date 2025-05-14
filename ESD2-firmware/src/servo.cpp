#include "servo.h"

void init_servo() {
    ledcSetup(SERVO_PWM_CHANNEL, 50, 16);
    ledcAttachPin(SERVO_PIN, SERVO_PWM_CHANNEL);
}

void set_servo_angle(uint8_t angle) {
    // Clamp angle
    angle = constrain(angle, 0, 180);

    // Map angle to microseconds pulse
    int pulseWidth = map(angle, 0, 180, 500, 2500);

    // Convert pulse width to duty cycle (0 - 65535)
    uint32_t duty = (uint32_t)((pulseWidth / 20000.0) * 65535); // 20ms = 50Hz period
    ledcWrite(SERVO_PWM_CHANNEL, duty);
}