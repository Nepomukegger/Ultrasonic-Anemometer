#ifndef NMEA2000HANDLER_H
#define NMEA2000HANDLER_H

#include <NMEA2000_CAN.h>
#include <N2kMessages.h>
#include "SensorHandler.h"
#include "SensorManager.h"
#include "config.h"

// Sensordatenstruktur
struct SensorData {
    double windSpeed;
    double windAngle;
    double temperature;
    double humidity;
};

void initNMEA2000();
void sendNMEA2000Data(const std::vector<double>& distances);

#endif
