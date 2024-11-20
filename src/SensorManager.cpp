#include "SensorManager.h"

void SensorManager::addSensor(int pin, int id, uint8_t mode) {
    // Sensoren hinzufügen
    sensorManager.emplace_back(pin , id, mode);
}

Sensor SensorManager::getSensorById(int id) {
    // Sensor anhand der ID zurückgeben
    for (Sensor & sensor : sensorManager) {
        if (sensor.getId() == id) {
            return sensor;
        }
    }
    return {-1, -1, 0};
}

Sensor SensorManager::getSensorByPin(int pin) {
    // Sensor anhand des Pins zurückgeben
    for (Sensor & sensor : sensorManager) {
        if (sensor.getPin() == pin) {
            return sensor;
        }
    }
    return {-1, -1, 0};
}