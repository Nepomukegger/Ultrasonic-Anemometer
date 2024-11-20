#pragma once
#include "config.h"
#include <esp_timer.h>
#include <Arduino.h>


struct UltrasonicSensor{
    UltrasonicSensor();
    int64_t measureTime();
    bool outputPWM();
};