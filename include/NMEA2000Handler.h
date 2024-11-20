#ifndef NMEA2000HANDLER_H
#define NMEA2000HANDLER_H

#include <NMEA2000_CAN.h>
#include <N2kMessages.h>
#include "DataHandler.h"

void initNMEA2000();
void sendNMEA2000Data(const PreparedData& data);

#endif
