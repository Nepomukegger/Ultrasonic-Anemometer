#include "SensorHandler.h"

void SensorHandler::init() {
    // Sensor-Pins initialisieren, falls nötig
    pinMode(ULTRASONIC_SENSOR_1_PIN_A, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_1_PIN_B, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_2_PIN_A, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_2_PIN_B, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_3_PIN_A, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_3_PIN_B, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_4_PIN_A, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_4_PIN_B, OUTPUT);
}

void SensorHandler::readSensorData(SensorData& data) {
    // Sensordaten abfragen
    data.measureTime = readMeasureTime();
}

int64_t SensorHandler::readMeasureTime() {
    // Logik zur Messung der Windgeschwindigkeit
    return 10; // Beispielwert
}
