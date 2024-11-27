
#ifndef PIN_H
#define PIN_H

#include <Arduino.h>

class Pin {
private:
    int pinNumber;
    uint8_t mode;

public:
    Pin(int pinNumber, uint8_t mode);
    int getPinNumber();
    uint8_t getMode();
};

#endif //PIN_H
