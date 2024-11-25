#include "WirelessHandler.h"

void initWireless() {
    WiFi.softAP(AP_SSID, WIFI_PASSWORD);
    IPAddress IP = WiFi.softAPIP();
    Serial.print(AP_SSID);
    Serial.print(" IP address: ");
    Serial.println(IP);
}

void sendWirelessData(const PreparedData& data) {
    // Beispiel: Sende die Daten per HTTP oder MQTT
    // Formatierung der Daten in ein geeignete Format (z.B. JSON)
    Serial.print("Sending data: ");
    Serial.print("WindSpeed: ");
    Serial.print(data.trueWind.magnitude());    //TODO: Implementierung der Funktion
    Serial.print(" WindAngle: ");
    Serial.print(data.windAngle);
    Serial.print(" Temp: ");
    Serial.print(data.temperature);
    Serial.print(" Humidity: ");
    Serial.println(data.humidity);
}
