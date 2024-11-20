#include "SensorHandler.h"

void SensorHandler::init() {
    // Sensor-Pins initialisieren, falls nötig
    pinMode(ULTRASONIC_SENSOR_1_WRITE_ENABLE, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_1_READ_ENABLE, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_2_WRITE_ENABLE, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_2_READ_ENABLE, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_3_WRITE_ENABLE, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_3_READ_ENABLE, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_4_WRITE_ENABLE, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_4_READ_ENABLE, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_CLK, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_READ, INPUT);
}

void SensorHandler::readSensorData(SensorData& data) {
    // Sensordaten abfragen
    data.measureTime = readMeasureTime();
}

int64_t SensorHandler::readMeasureTime() {
    // Logik zur Messung der Windgeschwindigkeit
    return 10; // Beispielwert
}
