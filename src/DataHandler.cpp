#include "DataHandler.h"

DataHandler DataHandler::processData() {
    // Setze den Zeitstempel
    this->timestamp = esp_timer_get_time();

    // Berechnung der Windgeschwindigkeit
    double time_x_forward = getSensorById(1).getRuntime() - getSensorById(3).getRuntime();
    double time_x_backward = getSensorById(3).getRuntime() - getSensorById(1).getRuntime();
    double time_y_forward = getSensorById(2).getRuntime() - getSensorById(4).getRuntime();  //TODO: Need to be adjusted
    double time_y_backward = getSensorById(4).getRuntime() - getSensorById(2).getRuntime(); //TODO: Need to be adjusted


    if ((sin(SENSOR_MOUNT_ANGLE_IN_RADIANS) + cos(SENSOR_MOUNT_ANGLE_IN_RADIANS)) != 0 && time_x_forward != 0 && time_x_backward != 0 && time_y_forward != 0 && time_y_backward != 0) {
        this->windX = (SENSOR_DISTANCE / (sin(SENSOR_MOUNT_ANGLE_IN_RADIANS) + cos(SENSOR_MOUNT_ANGLE_IN_RADIANS))) *
                   ((1 / time_x_forward) - (1 / time_x_backward));
        this->windY = (SENSOR_DISTANCE / (sin(SENSOR_MOUNT_ANGLE_IN_RADIANS) + cos(SENSOR_MOUNT_ANGLE_IN_RADIANS))) *
                   ((1 / time_y_forward) - (1 / time_y_backward));
        this->trueWind.add(this->windX);
        this->trueWind.add(this->windY);
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