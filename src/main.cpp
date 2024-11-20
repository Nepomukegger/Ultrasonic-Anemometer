/**
 * Ultrasonic Anemometer Project
 * 
 * Authors: Christopher Höck, Nepomuk Egger
 * Version: 1.0.0
 * Last updated: 20. November 2024
 * 
 * Project Summary:
 * This project aims to develop an ultrasonic anemometer using an ESP32 microcontroller. 
 * Key functionalities include:
 * - Measuring wind speed and direction using ultrasonic sensors.
 * - Monitoring temperature and humidity.
 * - Storing measured data locally on an SD card.
 * - Transmitting data wirelessly (Wi-Fi and Bluetooth).
 * - Supporting NMEA 2000 format for weather and geolocation data transmission.
 * 
 * Project Features:
 * - Modular code architecture for maintainability and scalability.
 * - Integration of NMEA 2000 standard for seamless communication with marine systems.
 * - Flexible configuration for sensor management and data processing.
 **/

#include <Arduino.h>
#include "config.h"
#include "NMEA2000Handler.h"
#include "WirelessHandler.h"
#include "SensorManager.h"
#include "DataHandler.h"

SensorManager sensorManager;
DataHandler dataHandler(0); // Initialisiere mit Laufzeit 0

void initializeSensors() {
    sensorManager.addSensor(ULTRASONIC_SENSOR_1_READ_ENABLE, 10, OUTPUT);
    sensorManager.addSensor(ULTRASONIC_SENSOR_1_WRITE_ENABLE, 11, OUTPUT);
    sensorManager.addSensor(ULTRASONIC_SENSOR_2_READ_ENABLE, 20, OUTPUT);
    sensorManager.addSensor(ULTRASONIC_SENSOR_2_WRITE_ENABLE, 21, OUTPUT);
    sensorManager.addSensor(ULTRASONIC_SENSOR_3_READ_ENABLE, 30, OUTPUT);
    sensorManager.addSensor(ULTRASONIC_SENSOR_3_WRITE_ENABLE, 31, OUTPUT);
    sensorManager.addSensor(ULTRASONIC_SENSOR_4_READ_ENABLE, 40, OUTPUT);
    sensorManager.addSensor(ULTRASONIC_SENSOR_4_WRITE_ENABLE, 41, OUTPUT);
    sensorManager.addSensor(ULTRASONIC_SENSOR_CLK, 50, OUTPUT);
    sensorManager.addSensor(ULTRASONIC_SENSOR_READ, 51, INPUT);
}

void setup() {
    Serial.begin(115200);

    // Initialisierungen
    initNMEA2000();
    initWireless();
    initializeSensors();

    Serial.println("Setup abgeschlossen.");
}

void loop() {
    static double runtime = 300; // Beispielwert, Laufzeit hier simuliert

    // Datenverarbeitung
    PreparedData data = dataHandler.processData(runtime);

    // Daten senden
    sendWirelessData(data);
    sendNMEA2000Data(data);

    delay(1000); // Intervall für die Messungen
}
