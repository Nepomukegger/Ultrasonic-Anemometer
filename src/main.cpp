#include <Arduino.h>
void setup() {
// write your initialization code here
    Serial.begin(9600);
    pinMode(19, INPUT);
}

void loop() {
// write your code here
    Serial.println(analogRead(19));
    delay(5000);
}