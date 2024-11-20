//
//Description: This file contains the declaration of the Sensor class.
//This class is used to create a sensor object that contains the GPIO number, id, mode and runtime of the sensor.
//The id isn't put by your development bord you can put any number you want.
//The mode is the mode of the GPIO pin, it can be INPUT or OUTPUT.
//

#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor {
public:
    Sensor(int pin, int id, uint8_t mode);
    int getPin();
    int getId();
    uint8_t getMode();
    void setRuntime(int64_t measuredTime);
    double getRuntime();
private:
    int pin;
    int id;
    uint8_t mode;
    int64_t runtime;
};



#endif //SENSOR_H
