#include "Pin.h"

Pin::Pin(int pinNumber, uint8_t mode) : pinNumber(pinNumber), mode(mode) {
    pinMode(pinNumber, mode);
}

int Pin::getPinNumber() {
    return pinNumber;
}

uint8_t Pin::getMode() {
    return mode;
}