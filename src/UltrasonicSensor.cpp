#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int trig, int echo) : triggerPin(trig), echoPin(echo) {}

void UltrasonicSensor::setup() {
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

double UltrasonicSensor::measureDistance() {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    return (duration * 0.0343) / 2; // Distanz in cm
}
