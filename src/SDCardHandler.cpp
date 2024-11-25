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

bool SDCardHandler::storeData(const PreparedData &data) {}
