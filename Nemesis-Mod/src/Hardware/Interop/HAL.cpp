#include <Arduino.h>
#include "HAL.h"

int HAL::analogReadSafe(uint8_t pin) {
    return analogRead(pin);
}

void HAL::analogWriteSafe(uint8_t pin, uint32_t value) {
    analogWrite(pin, value);
}

int HAL::digitalReadSafe(uint8_t pin) {
    return digitalRead(pin);
}

void HAL::digitalWriteSafe(uint8_t pin, uint32_t value) {
    digitalWrite(pin, value);
}

void HAL::pinModeSafe(uint8_t pin, PinMode mode) {
    switch (mode) {
        case PinMode::Input: {
            pinMode(pin, INPUT);
            break;
        }
        case PinMode::Output: { 
            pinMode(pin, OUTPUT);
            break;
        }
    }
}