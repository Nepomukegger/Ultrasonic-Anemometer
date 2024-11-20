#include "SensorHandler.h"

void SensorHandler::measureRuntime() {
    //todo: output pwm signal
    this -> setRuntime(esp_timer_get_time());
}

//TODO: remember which sensor send the signal
void SensorHandler::measureRuntimeIsr() {

  this -> setRuntime(esp_timer_get_time() - this -> getRuntime());
}