#include "DataHandler.h"

DataHandler::DataHandler() {
    // Initialisierungen, z. B. SD-Karten-Setup
}

PreparedData DataHandler::processData(const SensorData& data) {
    // Verarbeite die Sensordaten, z. B. Glättung oder Berechnungen
}

bool DataHandler::storeData(const PreparedData& data) {
    // Daten speichern (auf SD-Karte, in einem Array, etc.)
}
