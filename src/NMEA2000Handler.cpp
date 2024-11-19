#include "NMEA2000Handler.h"

tNMEA2000 &NMEA2000 = NMEA2000_CAN;

void initNMEA2000() {
    NMEA2000.SetProductInformation("123456", 200, "Ultrasonic Anemometer", "1.0.0", 1);
    NMEA2000.SetDeviceInformation(1, 130, 25, 2046);
    NMEA2000.Open();
}

void sendNMEA2000Data(const SensorData& data) {
    tN2kMsg N2kMsg;

    // PGN 130306: Winddaten senden
    SetN2kWindSpeed(N2kMsg, 1, data.windSpeed, data.windAngle, N2kWind_True_North);
    NMEA2000.SendMsg(N2kMsg);

    // PGN 130312: Temperaturdaten senden
    SetN2kTemperature(N2kMsg, 1, N2kts_MainCabinTemperature, data.temperature);
    NMEA2000.SendMsg(N2kMsg);
}
