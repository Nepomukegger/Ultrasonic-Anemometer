//
//Description: This file contains the implementation of the Sensor class.
//

#include "Sensor.h"

Sensor::Sensor(String name, int id, Pin pinRead, Pin pinWrite) : name(std::move(name)), pinRead(pinRead),
pinWrite(pinWrite), id(id), runtime(0) {
}

String Sensor::getName() {
    return name;
}

const Pin & Sensor::getPinRead() {
    return pinRead;
}

const Pin & Sensor::getPinWrite() {
    return pinWrite;
}

int Sensor::getId() {
    return id;
}

void Sensor::setRuntime(int64_t measuredTime) {
    this->runtime = measuredTime;
}

double Sensor::getRuntime() {
    return runtime; 
}