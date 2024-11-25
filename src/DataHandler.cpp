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
        this->windSpeed = this->trueWind.getMagnitude();
    }
    else {
        Serial.println("Fehler: Division durch Null oder ungültige Werte!");
    }

    // Berechnung des Windwinkels
   
   this->windAngle =  trueWind.getAngle();
    /* double sensor1_time = time_forwards; // TODO: Ersetze durch Sensorlaufzeiten
    double sensor2_time = time_backwards; // TODO: Ersetze durch Sensorlaufzeiten
    double wind_angle = 0.0;

    if (sensor1_time != 0 && sensor2_time != 0) {
        wind_angle = atan2(sensor2_time, sensor1_time) * 180.0 / M_PI; // Radiant in Grad
        Serial.println("Berechneter Windwinkel: " + String(wind_angle) + "°");
        data.setWindAngle(wind_angle);
    }
    else {
        Serial.println("Fehler: Ungültige Sensordaten für Winkelberechnung!");
    } */


    // Berechnung der Temperatur (z. B. direkt aus einem Sensorwert)
    double temperature = 0.0; // Beispielwert, TODO: Berechnung einfügen
    Serial.println("Berechnete Temperatur: " + String(temperature) + " °C");
    this->temperature = temperature;
    // TODO: Füge weitere Berechnungen hinzu, z. B. für Luftfeuchtigkeit oder andere Parameter

    return *this;
}

bool DataHandler::store(SDCardHandler cardInput, bool storeIt) {
        // Speichere die Daten lokal auf der SD-Karte
        if (!storeIt) {
            Serial.println("Speichern der Daten deaktiviert.");
            return false;
        }
        else {
            Serial.println("Speichern der Daten aktiviert.\n Speichere Daten auf SD-Karte...");
            cardInput.storeData(*this);
            return true;
        }
}