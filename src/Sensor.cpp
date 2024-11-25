//
//Description: This file contains the implementation of the Sensor class.
//

#include "Sensor.h"

Sensor::Sensor(String name, int pinRead, int pinWrite, int id, uint8_t modeRead, uint8_t modeWrite) : name(name), pinRead(pinRead), pinWrite(pinWrite), id(id), modeRead(modeRead), modeWrite(modeWrite), runtime(0) {
    pinMode(pinRead, modeRead);
    pinMode(pinWrite, modeWrite);
}

String Sensor::getName() {
    return name;
}

int Sensor::getPinRead() {
    return pinRead;
}

int Sensor::getPinWrite() {
    return pinWrite;
}

int Sensor::getId() {
    return id;
}

uint8_t Sensor::getModeRead() {
    return modeRead;
}

uint8_t Sensor::getModeWrite() {
    return modeWrite;
}

void Sensor::setRuntime(int64_t measuredTime) {
    this->runtime = measuredTime;
}

double Sensor::getRuntime() {
    return runtime;
}