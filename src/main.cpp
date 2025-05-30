#include <Arduino.h>
#include <map>
#include "config.h"
#include "Sensor.h"
#include "Calculate.h"
#include "GlobalVariables.h"


void setup() {
    // write your initialization code here
    Serial.begin(115200);
    Serial.println("Starting Wind Sensor...");
    pinMode(S1, OUTPUT);
    pinMode(S0, OUTPUT);
    pinMode(ENABLE, OUTPUT);
    pinMode(SIGNAL_OUT, OUTPUT);
    pinMode(SIGNAL_IN, INPUT);
    analogWriteFrequency(CLOCK_FREQUENCY);
}

void loop() {
// write your code here
    Serial.println("Start measuring...");
    Sensor::measureRuntime();
    Calculate::windSpeed();
    Calculate::windDirection();
    //Calculate::Temperature();
    Serial.print("1-3: ");
    Serial.print(runtime["1-3"]);
    Serial.print(" 2-4: ");
    Serial.print(runtime["2-4"]);
    Serial.print(" 3-1: ");
    Serial.print(runtime["3-1"]);
    Serial.print(" 4-2: ");
    Serial.println(runtime["4-2"]);
    delay(5000);
}