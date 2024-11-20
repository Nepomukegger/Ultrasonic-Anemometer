#ifndef SENSORHANDLER_H
#define SENSORHANDLER_H

#include <esp_timer.h>
#include <Arduino.h>
#include "config.h"
#include "SensorManager.h"

class SensorHandler {
public:
    void init();
    void readSensorData(SensorData& data);

private:
    // Hilfsfunktionen für die Sensorabfragen
    double readWindSpeed();
    double readWindAngle();
    double readTemperature();
    double readHumidity();
};

#endif
