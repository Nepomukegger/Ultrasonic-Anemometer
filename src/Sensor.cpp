//
//Description: This file contains the implementation of the Sensor class.
//

#include "Sensor.h"

Sensor::Sensor(int pin, int id, uint8_t mode) : pin(pin), id(id), mode(mode), runtime(0) {
    pinMode(pin, mode);
}

int Sensor::getPin() {
    return pin;
}

int Sensor::getId() {
    return id;
}

uint8_t Sensor::getMode() {
    return mode;
}

void Sensor::setRuntime(int64_t measuredTime) {
    this->runtime = measuredTime;
}

double Sensor::getRuntime() {
    return runtime;
}