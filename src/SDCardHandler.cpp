//
// Description: This file contains the implementation of the SDCardHandler class.
//

#include "SDCardHandler.h"

SDCardHandler::SDCardHandler() : filename("/measuerments.csv") {
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

SDCardHandler SDCardHandler::returnCSVFile() {
    return *this;
}

bool SDCardHandler::storeData(const DataHandler &data) {
    this->csvFile = SD_MMC.open(filename, FILE_APPEND);
    if (!csvFile) {
        Serial.println("Fehler beim Öffnen der Datei!");
        return false;
    }

    csvFile.print(data.timestamp); 
    csvFile.print(",");
    csvFile.print(data.windAngle);
    csvFile.print(",");
    csvFile.print(data.windSpeed);
    csvFile.print(",");
    csvFile.print(data.temperature);
    csvFile.print(",");
    csvFile.print(data.humidity);
    csvFile.println();
}
