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

// Initialisierung der Handler
SensorManager sensorManager;
SensorHandler sensorHandler;
WirelessHandler wirelessHandler;
NMEA2000Handler nmea2000Handler;
SDCardHandler cardHandler;
DataHandler preparedData;

void initializeSensors() {
    sensorManager.addSensor(ULTRASONIC_SENSOR_1_ECHO, ULTRASONIC_SENSOR_1_TRIGGER, 1, OUTPUT, OUTPUT);
    sensorManager.addSensor(ULTRASONIC_SENSOR_2_ECHO, ULTRASONIC_SENSOR_2_TRIGGER, 2, OUTPUT, OUTPUT);
    sensorManager.addSensor(ULTRASONIC_SENSOR_3_ECHO, ULTRASONIC_SENSOR_3_TRIGGER, 3, OUTPUT, OUTPUT);
    sensorManager.addSensor(ULTRASONIC_SENSOR_4_ECHO, ULTRASONIC_SENSOR_4_TRIGGER, 4, OUTPUT, OUTPUT);
}

void initializeClock() {
    sensorHandler.enableClock(ULTRASONIC_SENSOR_CLK, CLOCK_FREQUENCY, OUTPUT); //TODO: 305 kHz, needs to be adjusted
    sensorHandler.enableRead(ULTRASONIC_SENSOR_READ, INPUT);
}

void setup() {
    Serial.begin(115200);

    // Initialisierungen
    logError(esp_timer_get_time() + ": Setup wird durchgeführt...");
    
    initializeSensors();
    initializeClock();

    logError("Setup abgeschlossen.");
}

void loop() {

    // Datenverarbeitung
    preparedData.store(cardHandler, false);
    sensorHandler.readInput(ULTRASONIC_SENSOR_READ);
    preparedData.processData();
    preparedData.store(cardHandler, true);

    // Daten senden
    // wirelessHandler.sendWirelessData();
    nmea2000Handler.sendNMEA2000Data(preparedData);

    delay(1000); // Intervall für die Messungen
}
