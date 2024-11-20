#ifndef WIRELESSHANDLER_H
#define WIRELESSHANDLER_H

#include <WiFi.h>
#include "SensorManager.h"

void initWireless();
void sendWirelessData(const SensorData& data);

#endif
