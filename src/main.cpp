#include <Arduino.h>

const int ledPin = 1;           // LED Pin
const int dutyCycle = 128;       // PWM Duty Cycle (0-255)
const int freq = 305000;         // PWM Frequenz
const int resolution = 4;        // PWM Auflösung (z. B. 4 Bits, 0-15)
const int ledChannel = 0;        // PWM Kanal (0-15)
const int timer = 0;             // Timer für den PWM Kanal (0-1)

void setup() {
  // Konfiguriere den PWM-Kanal
  analogWriteFrequency(freq);
}

void loop() {
  // Setze den PWM-Wert (Duty Cycle) auf 8 (von 0 bis 15 bei einer Auflösung von 4 Bits)
  analogWrite(ledPin, dutyCycle);
  delay(1000); // Verzögerung von 1 Sekunde
}
