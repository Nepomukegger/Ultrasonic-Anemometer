/**
 * Ultrasonic Anemometer Project
 * 
 * Authors: Christopher Höck, Nepomuk Egger
 * Version: 1.0.0
 * Last updated: 2024-11-25
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
PreparedData data;

void initializeSensors() {
    sensorManager.addSensor(ULTRASONIC_SENSOR_1_READ_ENABLE, ULTRASONIC_SENSOR_1_WRITE_ENABLE, 1, OUTPUT, OUTPUT);
    sensorManager.addSensor(ULTRASONIC_SENSOR_2_READ_ENABLE, ULTRASONIC_SENSOR_2_WRITE_ENABLE, 2, OUTPUT, OUTPUT);
    sensorManager.addSensor(ULTRASONIC_SENSOR_3_READ_ENABLE, ULTRASONIC_SENSOR_3_WRITE_ENABLE, 3, OUTPUT, OUTPUT);
    sensorManager.addSensor(ULTRASONIC_SENSOR_4_READ_ENABLE, ULTRASONIC_SENSOR_4_WRITE_ENABLE, 4, OUTPUT, OUTPUT);
    sensorManager.enabelClock(ULTRASONIC_SENSOR_CLK, CLOCK_FREQUENCY, OUTPUT); //TODO: 305 kHz, needs to be adjusted
    sensorManager.readInput(ULTRASONIC_SENSOR_READ, INPUT);

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
    data.processData();

    // Daten senden
    sendWirelessData(data);
    sendNMEA2000Data(data);

    delay(1000); // Intervall für die Messungen
}
