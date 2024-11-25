#include "WirelessHandler.h"

WirelessHandler::WirelessHandler() : filename("/measurments.json") {
    WiFi.softAP(AP_SSID, AP_PASSWORD);
    IPAddress IP = WiFi.softAPIP();
    Serial.print(AP_SSID);
    Serial.print(" IP address: ");
    Serial.println(IP);

    File csvFile = SD_MMC.open("/measurments.csv", FILE_READ);
    if (!csvFile) {
        Serial.println("Fehler beim Öffnen der CSV-Datei!");
        return;
    }

    DynamicJsonDocument jsonDoc(1024);
    String line;
    while (csvFile.available()) {
        line = csvFile.readStringUntil('\n');
        int commaIndex = line.indexOf(',');
        if (commaIndex > 0) {
            String key = line.substring(0, commaIndex);
            String value = line.substring(commaIndex + 1);
            jsonDoc[key] = value;
        }
    }
    csvFile.close();

    File jsonFile = SD_MMC.open(filename, FILE_WRITE);
    if (!jsonFile) {
        Serial.println("Fehler beim Öffnen der JSON-Datei!");
        return;
    }
    serializeJson(jsonDoc, jsonFile);
    jsonFile.close();
}

void WirelessHandler::sendWirelessData() {
    //TODO: Implement wireless data transmission
}
