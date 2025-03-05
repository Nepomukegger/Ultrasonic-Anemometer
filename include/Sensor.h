#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include "config.h"


namespace Sensor {
	void measureRuntime();
	void SelectSensor(const std::pair<std::pair<int, int>, std::pair<int, int>> & pins);
};



#endif //SENSOR_H
