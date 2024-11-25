#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#include "config.h"
#include "SensorHandler.h"
#include "Sensor.h"
#include <vector>

class SensorManager : public SensorHandler {
public:
    void addSensor(int pinRead, int pinWrite, int id, uint8_t modeRead, uint8_t modeWrite);
    void enabelClock(int pin, int frequency, uint8_t mode);
    void readInput(int pin, uint8_t mode);
    Sensor getSensorByName(String name);
    Sensor getSensorById(int id);
    Sensor getSensorByPin(int pin); //TODO: Implementierung neu schreiben, da 2 Pins pro Sensor
private:
    std::vector<Sensor> sensorManager;
};

#endif
