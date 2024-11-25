#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include "config.h"
#include "SensorHandler.h"
#include "Sensor.h"
#include <vector>

class SensorManager : public SensorHandler {
private:
    std::vector<Sensor> sensorManager;

public:

    void addSensor(int pinRead, int pinWrite, int id, uint8_t modeRead, uint8_t modeWrite);
    Sensor getSensorByName(String name);
    Sensor getSensorById(int id);
    Sensor getSensorByPin(int pin); //TODO: Implementierung neu schreiben, da 2 Pins pro Sensor
};

#endif
