#include <Arduino.h>
#include <arduino-esp32/esp32-hal-ledc.h>

const int ledPin = 1;
const int freq = 305000;
const int resolution = 4;

void setup() {
// write your initialization code here
ledcAttach(ledPin, freq, resolution);
}

void loop() {
// write your code here
ledcWrite(ledPin, 8);
delay(100000);
}