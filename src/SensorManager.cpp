#include "SensorManager.h"

SensorManager::SensorManager() : sensorHandler() {}

void SensorManager::initSensors() {
    sensorHandler.init();
}

void SensorManager::updateSensors(SensorData& data) {
    sensorHandler.readSensorData(data);
}
