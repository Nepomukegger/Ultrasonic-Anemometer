#ifndef SDCARDHANDLER_H
#define SDCARDHANDLER_H

#include <SD_MMC.h>
#include <SPI.h>
#include "DataHandler.h"

class SDCardHandler {
public:
    SDCardHandler();
    bool storeData(const PreparedData& data);
};

#endif
