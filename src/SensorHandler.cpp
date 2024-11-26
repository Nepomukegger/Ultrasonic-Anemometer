//
// Description: This file contains the implementation of the SensorHandler class. This class is responsible for handling the sensors connected to the ESP32. 
// It provides methods to enable the clock for the sensors, read the input from the sensors, and measure the runtime of the sensors.
// 

#include "SensorHandler.h"

void SensorHandler::enableClock(int pin, int frequency, uint8_t mode)	// Enable clock for the sensor and Output PWM signal
{
    pinMode(pin, mode);
    ledcSetup(0, frequency, 8);  // Channel 0, specified frequency, 8-bit resolution (8 bits means the PWM duty cycle can range from 0 to 255)
    // ledcAttachPin(pin, 0);       // Attach pin to channel 0
}

void SensorHandler::enableRead(int pin)
{
	digitalWrite(pin, HIGH);
}

void SensorHandler::measureRuntime() {
    //todo: output pwm signal ???
    // ledcAttachPin(getPinWrite(), 0);		// Attach pin to channel 0
	// ledcDetachPin(getPinWrite());		// Detach pin from channel 0
	this -> setRuntime(esp_timer_get_time());
	// return this -> getId();
}

//TODO: remember which sensor send the signal
void SensorHandler::measureRuntimeIsr() {
	this -> setRuntime(esp_timer_get_time() - this -> getRuntime());
}