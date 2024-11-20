#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <cmath>
#include <SD.h>
#include <SPI.h>
#include "SensorManager.h"  // Enthält die SensorData-Struktur

class PreparedData {
public:
    double windSpeed;
    double windAngle;
    double temperature;
    double humidity;

    void setWindSpeed(double windSpeed);
    void setWindAngle(double windAngle);
    void setTemperature(double temperature);
    void setHumidity(double humidity);

private:

};

class DataHandler {
public:
    DataHandler(double runtime);
    PreparedData processData(double& runtime);
    bool storeData(const PreparedData& data);

private:
    // Speicherorte oder Pufferspeicherung
    double runtime; 
};

#endif
