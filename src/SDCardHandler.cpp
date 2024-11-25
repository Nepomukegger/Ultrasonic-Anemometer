//
// Description: This file contains the implementation of the SDCardHandler class.
//

#include "SDCardHandler.h"

SDCardHandler::SDCardHandler() {
    // TODO: SD-Karten-Setup
    if (!SD_MMC.begin()) {
        Serial.println("SD-Karte konnte nicht initialisiert werden!");
        while (true) {
            // Endlosschleife, wenn keine SD-Karte gefunden wird (nur für Debugging).
        }
    }
    else {
        Serial.println("SD-Karte erfolgreich initialisiert.");
    }
}

bool SDCardHandler::storeData(const PreparedData &data) {
    File file = SD_MMC.open("/measuerment.csv", FILE_APPEND);
    if (!file) {
        Serial.println("Fehler beim Öffnen der Datei!");
        return false;
    }

    file.print(data.timestamp);
    file.print(",");
    file.print(data.trueWind.magnitude()); //Implementierung von MathVec fehlt
    file.print(",");
    file.print(data.windDirection);
    file.print(",");
    file.print(data.temperature);
    file.print(",");
    file.print(data.humidity);
    file.print(",");
    file.print(data.pressure);
    file.println();
}
