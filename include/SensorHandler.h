#ifndef SENSORHANDLER_H
#define SENSORHANDLER_H

#include "Sensor.h"
#include "SensorManager.h"

class SensorHandler : public Sensor {
private:

public:
    void enableClock(int pin, int frequency, uint8_t mode);
    void enableRead(int pin, uint8_t mode);
    bool readInput(int pin);
    int measureRuntime();
    void measureRuntimeIsr();
};

#endif
