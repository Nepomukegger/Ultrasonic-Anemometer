#ifndef WIRELESSHANDLER_H
#define WIRELESSHANDLER_H

#include <WiFi.h>
#include <ArduinoJson.h>
#include "DataHandler.h"
#include "SDCardHandler.h"

class WirelessHandler : public SDCardHandler {
private:
    File jsonFile;
    String filename;
    
public:

    WirelessHandler();

    void sendWirelessData();
};

#endif
