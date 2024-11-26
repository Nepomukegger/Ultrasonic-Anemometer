#ifndef SENSORHANDLER_H
#define SENSORHANDLER_H

#include "Sensor.h"
#include "SensorManager.h"

class SensorHandler : public SensorManager {
private:

public:
    void enableClock(int pin, int frequency, uint8_t mode);
    void enableRead(int pin, uint8_t mode);
    void measureRuntime();
    void measureRuntimeIsr();
};

#endif
