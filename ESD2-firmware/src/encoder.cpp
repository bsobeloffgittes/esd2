#include "encoder.h"

void Encoder::initialize(uint8_t pinA, uint8_t pinB) {
    ESP32Encoder::useInternalWeakPullResistors = puType::up;

    this->encoder.attachHalfQuad(pinA, pinB);

    this->encoder.setCount(0);

    this->last_read_time = 0;
    this->last_read_counts = 0;
}

float Encoder::get_rpm() {
    int64_t new_time = esp_timer_get_time();
    int32_t new_counts = this->encoder.getCount();
    
    this->rpm = (((((float) (new_counts - this->last_read_counts)) / ENCODER_PPR) * 60000000.0) / ((float) (new_time - this-> last_read_time)));
    
    last_read_counts = new_counts;
    last_read_time = new_time;

    

    return this->rpm;
}
