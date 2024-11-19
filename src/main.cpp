#include <Arduino.h>
#include "config.h"
#include "NMEA2000Handler.h"
// #include "WirelessHandler.h" // Noch nicht implementiert
// #include "SensorManager.h"  // Noch nicht implementiert

void setup() {
    Serial.begin(115200);

    // Initialisierungen
    initNMEA2000();
    // initWireless(); // Noch nicht implementiert
    // initSensors();  // Noch nicht implementiert
}

void loop() {
    // SensorData data = readSensorData(); // Noch nicht implementiert
    SensorData data; // Platzhalter

    // Provisorische Werte für SensorData
    data.temperature = 20.0; 
    data.windSpeed = 10.0;

    sendNMEA2000Data(data);

    // sendWirelessData(data); // Noch nicht implementiert
    delay(100); // Intervall für Echtzeit-Messungen
}
