#include "DataHandler.h"

void PreparedData::setWindSpeed(double newWindSpeed) {
    this->windSpeed = newWindSpeed;
}

void PreparedData::setWindAngle(double newWindAngle) {
    this->windAngle = newWindAngle;
}

void PreparedData::setTemperature(double newTemperature) {
    this->temperature = newTemperature;
}

void PreparedData::setHumidity(double newHumidity) {
    this->temperature = newHumidity;
}

DataHandler::DataHandler(double runtime) : runtime(runtime) {
    // TODO: SD-Karten-Setup
    if (!SD_MMC.begin()) {
        Serial.println("SD-Karte konnte nicht initialisiert werden!");
        while (true) {
            // Endlosschleife, wenn keine SD-Karte gefunden wird (nur für Debugging).
        }
    } else {
        Serial.println("SD-Karte erfolgreich initialisiert.");
    }
}

PreparedData DataHandler::processData(double &runtime) {
    // Neues Objekt der Klasse PreparedData
    PreparedData data;

    // Berechnung der Windgeschwindigkeit
    double time_forwards = runtime;     // TODO: Hole die gemessene Laufzeit vorwärts
    double time_backwards = runtime;    // TODO: Hole die gemessene Laufzeit rückwärts
    double angle = 45.0;                // Beispiel: Sensorwinkel, anpassen
    double angle_in_radians = angle * M_PI / 180.0; // Grad in Radiant umrechnen
    double distance = cos(angle_in_radians) * 10;   // TODO: Setze hier die Sensordistanz ein
    double velocity = 0.0;

    if ((sin(angle_in_radians) + cos(angle_in_radians)) != 0 && time_forwards != 0 && time_backwards != 0) {
        velocity = (distance / (sin(angle_in_radians) + cos(angle_in_radians))) *
                   ((1 / time_forwards) - (1 / time_backwards));
        Serial.println("Berechnete Geschwindigkeit: " + String(velocity) + " m/s");
        data.setWindSpeed(velocity);
    } else {
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
    } else {
        Serial.println("Fehler: Ungültige Sensordaten für Winkelberechnung!");
    }

    // Berechnung der Temperatur (z. B. direkt aus einem Sensorwert)
    double temperature = 0.0; // Beispielwert, TODO: Berechnung einfügen
    Serial.println("Berechnete Temperatur: " + String(temperature) + " °C");
    data.setTemperature(temperature);

    // TODO: Füge weitere Berechnungen hinzu, z. B. für Luftfeuchtigkeit oder andere Parameter

    return data;
}

bool DataHandler::storeData(const PreparedData& data) {
    //TODO: Daten speichern (auf SD-Karte, in einem Array, etc.)
    File dataFile = SD_MMC.open("datalog.txt", FILE_WRITE);

    if (dataFile) {
        dataFile.print("Windgeschwindigkeit: ");
        dataFile.print(data.windSpeed);
        dataFile.print(" m/s, Windwinkel: ");
        dataFile.print(data.windAngle);
        dataFile.print("°, Temperatur: ");
        dataFile.print(data.temperature);
        dataFile.println(" °C");
        dataFile.close();
        Serial.println("Daten erfolgreich gespeichert!");
        return true;
    } else {
        Serial.println("Fehler beim Öffnen der Datei!");
        return false;
    }
}
