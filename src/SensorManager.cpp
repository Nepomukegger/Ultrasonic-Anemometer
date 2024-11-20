#include "SensorManager.h"

void SensorManager::addSensor(UltrasonicSensor* sensor) {
    sensors.push_back(sensor);
}

void SensorManager::setupSensors() {
    for (auto& sensor : sensors) {
        sensor->setup();
    }
}

std::vector<double> SensorManager::collectDistances() {
    std::vector<double> distances;
    for (auto& sensor : sensors) {
        distances.push_back(sensor->measureDistance());
    }
    return distances;
}
