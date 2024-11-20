#ifndef WIRELESSHANDLER_H
#define WIRELESSHANDLER_H

#include <WiFi.h>
#include "DataHandler.h"

void initWireless();
void sendWirelessData(const PreparedData& data);

#endif
