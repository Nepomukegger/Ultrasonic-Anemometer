#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <vector>
#include "UltrasonicSensor.h"

class SensorManager {
private:
    std::vector<UltrasonicSensor*> sensors;

public:
    void addSensor(UltrasonicSensor* sensor);
    void setupSensors();
    std::vector<double> collectDistances();
};

#endif
