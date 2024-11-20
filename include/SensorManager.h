#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include "config.h"
#include "SensorHandler.h"

struct SensorData {
    int64_t measureTime();
};

class SensorManager {
public:
    SensorManager();
    void initSensors();
    void updateSensors(SensorData& data);

private:
    SensorHandler sensorHandler;
};

#endif
