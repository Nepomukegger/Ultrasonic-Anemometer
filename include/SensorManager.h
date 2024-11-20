#include "config.h"
#include <esp_timer.h>


struct Sensor{
    int setup();
    int64_t measureTime();
    bool outputPWM();
};