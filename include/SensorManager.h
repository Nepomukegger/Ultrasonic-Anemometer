#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include "config.h"
#include "SensorHandler.h"
#include "Sensor.h"
#include <vector>

class SensorManager : public SensorHandler {
public:
    SensorManager();
    void addSensor(int pin, int id, uint8_t mode);
    Sensor getSensorById(int id);
    Sensor getSensorByPin(int pin);
private:
    std::vector<Sensor> sensorManager;
};

#endif
