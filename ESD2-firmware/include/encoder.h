#pragma once

#include <ESP32Encoder.h>
#include "esp_timer.h"
#include "global.h"

#define ENCODER_PPR 294

class Encoder {
    public:
        void initialize(uint8_t pinA, uint8_t pinB);
        float get_rpm();
    private:
        ESP32Encoder encoder;
        float rpm;
        int64_t last_read_time;
        int32_t last_read_counts;


    
};