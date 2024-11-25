#ifndef SDCARDHANDLER_H
#define SDCARDHANDLER_H

#include <SD_MMC.h>
#include <SPI.h>
#include "ErrorHandler.h"
#include "DataHandler.h"

class SDCardHandler {
private:
    File csvFile;
    String filename;

public:
    
    SDCardHandler();

    SDCardHandler returnCSVFile();
    bool storeData(const DataHandler& data);
};

#endif
