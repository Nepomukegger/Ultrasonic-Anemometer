#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include "SensorManager.h"  // Enthält die SensorData-Struktur

class DataHandler {
public:
    DataHandler();
    void processData(const SensorData& data);
    void storeData(const SensorData& data);

private:
    // Speicherorte oder Pufferspeicherung
};

#endif
