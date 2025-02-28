//
// Created by nepom on 28.02.2025.
//

#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include "config.h"


class Sensor {
public:
	void measure();
private:
	void SelectSensor(const std::pair<std::pair<int, int>, std::pair<int, int>> & pins);
};



#endif //SENSOR_H
