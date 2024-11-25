// 
// Description: This class prepares the sensor data and saves it.
//


#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <cmath>
#include <SD_MMC.h>
#include <SPI.h>
#include "SensorManager.h"  // Enthält die SensorData-Struktur
#include "MathVec.h"

class PreparedData : public SensorManager{
public:
    void processData();
    bool store();
private:
    // TODO: Wind Richtung berechnen
    MathVec windX;
    MathVec windY;
    MathVec trueWind; // TODO: Kann nicht zugegriffen werden in NMEA2000Handler.cpp & WirelessHandler.cpp, da privat
    double temperature;
    double humidity;
};


#endif
