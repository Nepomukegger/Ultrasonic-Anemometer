// 
// Description: This class prepares the sensor data and saves it.
//


#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <cmath>
#include <SD_MMC.h>
#include <SPI.h>
#include "SensorManager.h"
#include "SDCardHandler.h"
#include "MathVec.h"

class DataHandler : public SensorManager{
private:
    MathVec windX;
    MathVec windY;
    MathVec trueWind;

public:
    double timestamp;
    double windVelocity;
    double windDirection;
    double temperature;
    double humidity;

    DataHandler processData();  //ist der rückgabewert richtig? nicht void?
    bool store(SDCardHandler cardInput, bool storeIt);
};


#endif
