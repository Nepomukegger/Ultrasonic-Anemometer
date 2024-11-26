#include "DataHandler.h"

DataHandler DataHandler::processData() {
    // Setze den Zeitstempel
    this->timestamp = esp_timer_get_time();

    // Berechnung der Windgeschwindigkeit
    //runtime von sensor 1 ist zeit vorwärts und sensor 3 ist zeit rückwärts
    //das gleiche gilt auch für sensor 2 und 4


    if ((sin(SENSOR_MOUNT_ANGLE_IN_RADIANS) + cos(SENSOR_MOUNT_ANGLE_IN_RADIANS)) != 0 && getSensorById(1).getRuntime() != 0 && getSensorById(2).getRuntime() != 0 && getSensorById(3).getRuntime() != 0 && getSensorById(4).getRuntime() != 0) {
        this->windX = {SENSOR_DISTANCE / (sin(SENSOR_MOUNT_ANGLE_IN_RADIANS) + cos(SENSOR_MOUNT_ANGLE_IN_RADIANS)) *
                   (1 / getSensorById(1).getRuntime() - 1 / getSensorById(3).getRuntime()) ,0};
        this->windY = {0, SENSOR_DISTANCE / (sin(SENSOR_MOUNT_ANGLE_IN_RADIANS) + cos(SENSOR_MOUNT_ANGLE_IN_RADIANS)) *
                   (1 / getSensorById(2).getRuntime() - 1 / getSensorById(4).getRuntime())};
        this->trueWind = this->windX.add(this->windY);
        this->windVelocity = this->trueWind.getMagnitude();
        logError("Berechnete Windgeschwindigkeit: " + String(this->trueWind.getMagnitude()) + " m/s");
    }
    else {
        logError("Fehler: Division durch Null oder ungültige Werte!");
    }

    // Berechnung des Windwinkels

    this->windDirection =  trueWind.getAngle();
    logError("Berechneter Windwinkel: " + String(windDirection) + " °");

    // Berechnung der Temperatur (z. B. direkt aus einem Sensorwert)
    double temperature = 0.0; // Beispielwert, TODO: Berechnung einfügen
    logError("Berechnete Temperatur: " + String(temperature) + " °C");
    this->temperature = temperature;

    // TODO: Füge weitere Berechnungen hinzu, z. B. für Luftfeuchtigkeit oder andere Parameter
    double humidity = 0.0; // Beispielwert, TODO: Berechnung einfügen
    logError("Berechnete Luftfeuchtigkeit: " + String(humidity) + " %");
    this->humidity = humidity;

    return *this;
}

bool DataHandler::store(SDCardHandler cardInput, bool storeIt) {
        // Speichere die Daten lokal auf der SD-Karte
        if (!storeIt) {
            logError("Speichern der Daten deaktiviert.");
            return false;
        }
        else {
            logError("Speichern der Daten aktiviert.\n Speichere Daten auf SD-Karte...");
            cardInput.storeData(*this);
            return true;
        }
}