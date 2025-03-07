#include <Arduino.h>

#define LED 2

void setup() {
  // Set pin mode
  pinMode(LED,OUTPUT);
  analogWriteFrequency(305000);
}

void loop() {
analogWrite(LED, 128);
delay(100000);
}