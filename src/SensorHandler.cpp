#include "SensorHandler.h"
#include <Arduino.h>

void SensorHandler::processDistances(const std::vector<double>& distances) {
    for (size_t i = 0; i < distances.size(); i++) {
        Serial.print("Sensor ");
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.print(distances[i]);
        Serial.println(" cm");
    }
}
