// 
// Description: This class prepares the sensor data and saves it.
//


#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <cmath>
#include <SD_MMC.h>
#include <SPI.h>
#include "SensorManager.h"  // Enthält die SensorData-Struktur
#include "SDCardHandler.h"
#include "MathVec.h"

class PreparedData : public SensorManager{
private:
    // TODO: Wind Richtung berechnen
    // TODO: Zeitstempel hinzufügen
    MathVec windX;
    MathVec windY;
    MathVec trueWind; // TODO: Kann nicht zugegriffen werden in NMEA2000Handler.cpp & WirelessHandler.cpp, da privat

public:
    double windSpeed;
    double windAngle;
    double temperature;
    double humidity;

    PreparedData processData();
    bool store(SDCardHandler cardInput, bool storeIt);
};


#endif
