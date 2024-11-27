//
//Description: This file contains the declaration of the Sensor class.
//This class is used to create a sensor object that contains the GPIO number, id, mode and runtime of the sensor.
//The id isn't put by your development bord you can put any number you want.
//The mode is the mode of the GPIO pin, it can be INPUT or OUTPUT.
//

#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include <string>
#include <vector>

#include "Pin.h"

class Sensor {
    String name;
    Pin pinRead;
    Pin pinWrite;
    int id;
    int64_t runtime;

public:
    Sensor(String name, int id, Pin pinRead, Pin pinWrite);

    String getName();
    const Pin & getPinRead();
    const Pin & getPinWrite();
    int getId();
    void setRuntime(int64_t measuredTime);
    double getRuntime();

};

#endif //SENSOR_H
