#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include "SensorManager.h"  // Enthält die SensorData-Struktur

struct PreparedData {
    double measureTime;
    double windAngle;
    double temperature;
    double humidity;
};

class DataHandler {
public:
    DataHandler();
    PreparedData processData(const SensorData& data);
    bool storeData(const PreparedData& data);

private:
    // Speicherorte oder Pufferspeicherung
};

#endif
