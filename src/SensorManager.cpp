#include "SensorManager.h"

void SensorManager::addSensor(int pinRead, int pinWrite, int id, uint8_t modeRead, uint8_t modeWrite) {
    // Sensoren hinzufügen
    sensorManager.emplace_back("Sensor_" + std::to_string(id), pinRead, pinWrite, id, modeRead, modeWrite);     //TODO: change name
}

Sensor SensorManager::getSensorByName(String name) {
    // Sensor anhand des Namens zurückgeben
    try {
        for (Sensor & sensor : sensorManager) {
            if (sensor.getName() == name) {
                return sensor;
            }
        }
    } catch (const std::exception & e) {
        logError(e.what());
        return {"Error not found by name", -1, -1, -1, 0, 0};
    }
}

Sensor SensorManager::getSensorById(int id) {
    // Sensor anhand der ID zurückgeben
    try {
        for (Sensor & sensor : sensorManager) {
            if (sensor.getId() == id) {
                return sensor;
            }
        }
        // return sensorManager.at(id);     // Maybe better?
    } catch (const std::exception & e) {
        logError(e.what());
        return {"Error not found by ID", -1, -1, -1, 0, 0};
    }
    return {"Error not found by ID", -1, -1, -1, 0, 0};
}

Sensor SensorManager::getSensorByPin(int pin) {
    // Sensor anhand der Pins zurückgeben
    try {
        for (Sensor & sensor : sensorManager) {
            if (sensor.getPinRead() == pin || sensor.getPinWrite() == pin) {
                return sensor;
            }
        }
    } catch (const std::exception & e) {
        logError(e.what());
        return {"Error not found by pin", -1, -1, -1, 0, 0};
    }
}