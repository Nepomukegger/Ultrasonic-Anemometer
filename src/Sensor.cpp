//
// Created by nepom on 28.02.2025.
//

#include "Sensor.h"

void Sensor::measure() {
    int64_t pwm_time_sent;
    int64_t pwm_time_received;
    for (auto & e : SelectPins) {
        SelectSensor(e.second);
        delayMicroseconds(10);
        pwm_time_sent = esp_timer_get_time();
        analogWrite(SIGNAL_OUT, 128);
        while (analogRead(SIGNAL_IN) < 240) {
            //wait for signal to be received
        }
        pwm_time_received = esp_timer_get_time();
        while ((esp_timer_get_time() - pwm_time_sent) < 39) {
            //wait for burst to end
        }
        analogWrite(SIGNAL_OUT, 0);
    }
}

void Sensor::SelectSensor(const std::pair<std::pair<int, int>, std::pair<int, int>> & pins) {
    digitalWrite(pins.first.first, pins.first.second);
    digitalWrite(pins.second.first, pins.second.second);
}