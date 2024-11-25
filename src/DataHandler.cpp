#include "DataHandler.h"

void PreparedData::processData() {
    // Berechnung der Windgeschwindigkeit
    double time_x = getSensorById(1).getRuntime() - getSensorById(3).getRuntime();     // TODO: Id der sensoren anpassen
    double time_y = getSensorById(2).getRuntime() - getSensorById(4).getRuntime();

    if ((sin(angle_in_radians) + cos(angle_in_radians)) != 0 && time_forwards != 0 && time_backwards != 0) {
        velocity = (distance / (sin(angle_in_radians) + cos(angle_in_radians))) *
                   ((1 / time_forwards) - (1 / time_backwards));
        Serial.println("Berechnete Geschwindigkeit: " + String(velocity) + " m/s");
        data.setWindSpeed(velocity);
    }
    else {
        Serial.println("Fehler: Division durch Null oder ungültige Werte!");
    }

    // Berechnung des Windwinkels
    double sensor1_time = time_forwards; // TODO: Ersetze durch Sensorlaufzeiten
    double sensor2_time = time_backwards; // TODO: Ersetze durch Sensorlaufzeiten
    double wind_angle = 0.0;

    if (sensor1_time != 0 && sensor2_time != 0) {
        wind_angle = atan2(sensor2_time, sensor1_time) * 180.0 / M_PI; // Radiant in Grad
        Serial.println("Berechneter Windwinkel: " + String(wind_angle) + "°");
        data.setWindAngle(wind_angle);
    }
    else {
        Serial.println("Fehler: Ungültige Sensordaten für Winkelberechnung!");
    }

    // Berechnung der Temperatur (z. B. direkt aus einem Sensorwert)
    double temperature = 0.0; // Beispielwert, TODO: Berechnung einfügen
    Serial.println("Berechnete Temperatur: " + String(temperature) + " °C");
    data.setTemperature(temperature);

    // TODO: Füge weitere Berechnungen hinzu, z. B. für Luftfeuchtigkeit oder andere Parameter

    return data;
}