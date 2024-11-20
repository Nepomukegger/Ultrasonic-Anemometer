#include "NMEA2000Handler.h"

void initNMEA2000() {
    NMEA2000.SetProductInformation("123456", 200, "Ultrasonic Anemometer", "1.0.0", "1.0.0");
    NMEA2000.SetDeviceInformation(1, 130, 25, 2046);
    NMEA2000.Open();
}

void sendNMEA2000Data(const std::vector<double>& distances) {
    tN2kMsg N2kMsg;
    for (size_t i = 0; i < distances.size(); i++) {
        // PGN 130306: Winddaten senden
        SetN2kWindSpeed(N2kMsg, 1, distances[i], N2kWind_True_North);
        if (NMEA2000.SendMsg(N2kMsg)) {
            Serial.println("Wind data sent successfully!");
        } else {
            Serial.println("Failed to send wind data!");
        }
    }
/* 
    // PGN 130312: Temperaturdaten senden
    SetN2kTemperature(N2kMsg, 1, 1, N2kts_OutsideTemperature, data.temperature);
    if (NMEA2000.SendMsg(N2kMsg)) {
        Serial.println("Temperature data sent successfully!");
    } else {
        Serial.println("Failed to send temperature data!");
    }

    // PGN 130313: Feuchtigkeitsdaten senden
    SetN2kHumidity(N2kMsg, 1, 1, N2khs_OutsideHumidity, data.humidity);
    if (NMEA2000.SendMsg(N2kMsg)) {
        Serial.println("Humidity data sent successfully!");
    } else {
        Serial.println("Failed to send humidity data!");
    } */
}
