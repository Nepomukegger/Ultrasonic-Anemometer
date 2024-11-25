#include "SensorManager.h"

void SensorManager::addSensor(int pinRead, int pinWrite, int id, uint8_t modeRead, uint8_t modeWrite) {
    // Sensoren hinzufügen
    sensorManager.emplace_back("Sensor_" + std::to_string(id), pinRead, pinWrite, id, modeRead, modeWrite);
}

Sensor SensorManager::getSensorByName(String name) {
    // Sensor anhand des Namens zurückgeben
    for (Sensor & sensor : sensorManager) {
        if (sensor.getName() == name) {
            return sensor;
        }
    }
    return {"", -1, -1, -1, 0, 0};
}

Sensor SensorManager::getSensorById(int id) {
    // Sensor anhand der ID zurückgeben
    for (Sensor & sensor : sensorManager) {
        if (sensor.getId() == id) {
            return sensor;
        }
    }
    return {"", -1, -1, -1, 0, 0};
}

Sensor SensorManager::getSensorByPin(int pin) {
    //TODO: Sensor anhand der Pins zurückgeben
}