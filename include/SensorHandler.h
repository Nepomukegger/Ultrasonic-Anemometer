#ifndef SENSOR_HANDLER_H
#define SENSOR_HANDLER_H

#include <vector>

// Sensordatenstruktur
struct SensorData {
    double windSpeed;
    double windAngle;
    double temperature;
    double humidity;
};

class SensorHandler {
public:
    void processDistances(const std::vector<double>& distances);
};

#endif
