#ifndef SD_CARD_HANDLER_H
#define SD_CARD_HANDLER_H

#include <SD_MMC.h>
#include <SPI.h>
#include "DataHandler.h"

class SDCardHandler {
public:
    SDCardHandler();
    bool storeData(const PreparedData& data);
};

#endif
