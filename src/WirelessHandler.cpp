#include "WirelessHandler.h"

void initWireless() {
    WiFi.softAP(WIFI_SSID, WIFI_PASSWORD);
    IPAddress IP = WiFi.softAPIP();
    Serial.print(WIFI_SSID);
    Serial.print(" IP address: ");
    Serial.println(IP);
}