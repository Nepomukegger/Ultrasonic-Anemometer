#ifndef SENSORHANDLER_H
#define SENSORHANDLER_H

#include "Sensor.h"

class SensorHandler : public Sensor {
public:
    void measureRuntime();
    void measureRuntimeIsr();
};

#endif
