#ifndef WIRELESSHANDLER_H
#define WIRELESSHANDLER_H

#include <WiFi.h>
#include "config.h"
#include "SensorHandler.h"
#include "SensorManager.h"

void initWireless();
void sendWirelessData(const std::vector<double>& distances, const SensorData& data);

#endif
