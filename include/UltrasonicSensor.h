#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include <Arduino.h>

class UltrasonicSensor {
private:
    int triggerPin;
    int echoPin;

public:
    UltrasonicSensor(int trig, int echo);
    void setup();
    double measureDistance();
};

#endif
