#include "SensorManager.h"

UltrasonicSensor::UltrasonicSensor(){
    //Set the used Pins to output and input;
    pinMode(ULTRASONIC_SENSOR_1_PIN_A, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_1_PIN_B, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_2_PIN_A, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_2_PIN_B, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_3_PIN_A, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_3_PIN_B, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_4_PIN_A, OUTPUT);
    pinMode(ULTRASONIC_SENSOR_4_PIN_B, OUTPUT);
}