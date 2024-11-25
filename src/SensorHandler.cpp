#include "SensorHandler.h"
#include <Arduino.h>

SensorData SensorHandler::getSensorData() const {
    SensorData sensorData;
    sensorData.windSpeed = 0.0;
    sensorData.windAngle = 0.0;
    sensorData.temperature = 0.0;
    sensorData.humidity = 0.0;

    return sensorData;
}

void SensorHandler::processDistances(const std::vector<double>& distances) {
    for (size_t i = 0; i < distances.size(); i++) {
        Serial.print("Sensor ");
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.print(distances[i]);
        Serial.println(" cm");
    }
}
