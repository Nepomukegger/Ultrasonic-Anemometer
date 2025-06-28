#include "Sensor.h"
#include "config.h"
#include "GlobalVariables.h"

void Sensor::measureRuntime() {
    int64_t pwm_time_sent;
    int64_t pwm_time_received;
    for (auto & e : SelectPins) {
        Sensor::SelectSensor(e.second);
        delayMicroseconds(10);
        pwm_time_sent = esp_timer_get_time();
        analogWrite(SIGNAL_OUT, 128);
        while (digitalRead(SIGNAL_IN) < 1 && (esp_timer_get_time() - pwm_time_sent) < 1000) {
            //wait for signal to be received
        }
        pwm_time_received = esp_timer_get_time();
        while ((esp_timer_get_time() - pwm_time_sent) < 39) {
            //wait for burst to end
        }
        analogWrite(SIGNAL_OUT, 0);
        runtime[e.first] = pwm_time_received - pwm_time_sent;
        digitalWrite(LED_PIN, HIGH); // Turn on LED to indicate measurement is done
        delay(1000); // Keep LED on for a short time
        digitalWrite(LED_PIN, LOW); // Turn off LED
    }
}

void Sensor::SelectSensor(const std::pair<std::pair<int, int>, std::pair<int, int>> & pins) {
    digitalWrite(pins.first.first, pins.first.second);
    digitalWrite(pins.second.first, pins.second.second);
}