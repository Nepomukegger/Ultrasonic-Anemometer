#include <Arduino.h>
#include "config.h"
#include "NMEA2000Handler.h"
#include "WirelessHandler.h"
#include "SensorManager.h"
#include "DataHandler.h"

SensorManager sensorManager;
DataHandler dataHandler;

void setup() {
    Serial.begin(115200);

    // Initialisierungen
    initNMEA2000();
    initWireless();
    sensorManager.initSensors();
}

void loop() {
    SensorData data;
    sensorManager.updateSensors(data);

    // Datenverarbeitung
    dataHandler.processData(data);
    dataHandler.storeData(data);

    // Daten senden
    sendWirelessData(data);
    sendNMEA2000Data(data);

    delay(1000); // Intervall für die Messungen
}
