#include <Arduino.h>
#include <map>
#include "config.h"
#include "Sensor.h"
#include "Calculate.cpp"


Sensor ultrasonicSensor;


void setup() {
    // write your initialization code here

}

void loop() {
// write your code here
    ultrasonicSensor.measure();
    Calculate::windSpeed();
    Calculate::windDirection();
    Calculate::Temperature();
}