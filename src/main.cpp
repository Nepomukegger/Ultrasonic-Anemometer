#include <Arduino.h>
#include <map>
#include "config.h"
#include "Sensor.h"
#include "Calculate.cpp"


void setup() {
    // write your initialization code here
    Serial.begin(9500);
    pinMode(S1, OUTPUT);
    pinMode(S0, OUTPUT);
    pinMode(ENABLE, OUTPUT);
    pinMode(SIGNAL_OUT, OUTPUT);
    pinMode(SIGNAL_IN, INPUT);
}

void loop() {
// write your code here
    Sensor::measureRuntime();
    Calculate::windSpeed();
    Calculate::windDirection();
    Calculate::Temperature();
    delay(500);
}