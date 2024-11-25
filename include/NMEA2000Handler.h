#ifndef NMEA2000HANDLER_H
#define NMEA2000HANDLER_H

#include <NMEA2000_CAN.h>
#include <N2kMessages.h>
#include "DataHandler.h"


class NMEA2000Handler {
public:
    NMEA2000Handler();
    void sendNMEA2000Data(const DataHandler& data);
};

#endif
