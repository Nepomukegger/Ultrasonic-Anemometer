#include <Arduino.h>
#include "SensorManager.h"
#include "SensorHandler.h"
#include "NMEA2000Handler.h"

SensorManager sensorManager;
SensorHandler sensorHandler;

void setup() {
    Serial.begin(BAUD_RATE);

    // Sensoren hinzufügen
    sensorManager.addSensor(new UltrasonicSensor(SENSOR_1_TRIGGER_PIN, SENSOR_1_ECHO_PIN));
    sensorManager.addSensor(new UltrasonicSensor(SENSOR_2_TRIGGER_PIN, SENSOR_2_ECHO_PIN));
    sensorManager.addSensor(new UltrasonicSensor(SENSOR_3_TRIGGER_PIN, SENSOR_3_ECHO_PIN));
    sensorManager.addSensor(new UltrasonicSensor(SENSOR_4_TRIGGER_PIN, SENSOR_4_ECHO_PIN));

    sensorManager.setupSensors();
    initNMEA2000();
}

void loop() {
    auto distances = sensorManager.collectDistances();
    sensorHandler.processDistances(distances);
    sendNMEA2000Data(distances);

    delay(1000);
}
