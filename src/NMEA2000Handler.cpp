#include "NMEA2000Handler.h"

NMEA2000Handler::NMEA2000Handler() {
    NMEA2000.SetForwardStream(&Serial);
    NMEA2000.SetForwardType(tNMEA2000::fwdt_Text);
    NMEA2000.SetMode(tNMEA2000::N2km_ListenAndNode, NMEA2000_DEVICE_UNIQUE_NUMBER);
    NMEA2000.SetProductInformation( NMEA2000_DEVICE_UNIQUE_NUMBER, NMEA2000_DEVICE_NMEA2000_VERSION, NMEA2000_DEVICE_MANUFACTURER, NMEA2000_DEVICE_INSTALLATION_DESCRIPTION, NMEA2000_DEVICE_SOFTWARE_VERSION);
    NMEA2000.SetDeviceInformation(NMEA2000_DEVICE_INSTANCE, NMEA2000_DEVICE_FUNCTION, NMEA2000_DEVICE_CLASS, NMEA2000_DEVICE_MANUFACTURER_CODE);
    NMEA2000.EnableForward(false);
    NMEA2000.Open();
}

void NMEA2000Handler::sendNMEA2000Data(const DataHandler& data) {
    tN2kMsg N2kMsg;

    // PGN 130306: Winddaten senden
    SetN2kWindSpeed(N2kMsg, 1, data.windSpeed, data.windAngle, N2kWind_True_North);      //TODO: Implementierung der Funktion
    if (NMEA2000.SendMsg(N2kMsg)) {
        Serial.println("Wind data sent successfully!");
    } else {
        Serial.println("Failed to send wind data!");
    }

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
    }
}
