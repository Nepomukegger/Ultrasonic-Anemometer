#include <Arduino.h>
#include "NMEA2000Handler.h"
#include "WirelessHandler.h"
#include "SensorManager.h"

void setup() {
    Serial.begin(115200);

    // Initialisierungen
    initNMEA2000();
    initWireless();
    initSensors();
}

void loop() {
    // Sensordaten abrufen
    SensorData data = readSensorData();

    // NMEA2000-Daten senden
    sendNMEA2000Data(data);

    // Drahtlose Schnittstellen bedienen
    sendWirelessData(data);

    delay(100); // Intervall für Echtzeit-Messungen
}
