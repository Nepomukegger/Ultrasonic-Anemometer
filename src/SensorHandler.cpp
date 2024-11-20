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
    data.windSpeed = readWindSpeed();
    data.windAngle = readWindAngle();
    data.temperature = readTemperature();
    data.humidity = readHumidity();
}

double SensorHandler::readWindSpeed() {
    // Logik zur Messung der Windgeschwindigkeit
    return 10.0; // Beispielwert
}

double SensorHandler::readWindAngle() {
    // Logik zur Messung des Windwinkels
    return 30.0; // Beispielwert
}

double SensorHandler::readTemperature() {
    // Logik zur Messung der Temperatur
    return 20.0; // Beispielwert
}

double SensorHandler::readHumidity() {
    // Logik zur Messung der Luftfeuchtigkeit
    return 55.0; // Beispielwert
}
