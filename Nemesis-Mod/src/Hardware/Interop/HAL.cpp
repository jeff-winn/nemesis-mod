#include <Arduino.h>
#include "HAL.h"

void HAL::attachInterruptSafe(uint8_t pin, void (*userFunc)(void), InterruptMode mode) {
    int m = CHANGE;

    switch (mode) {
        case InterruptMode::Rising: {
            m = RISING;
            break;
        }
        case InterruptMode::Falling: {
            m = FALLING;
            break;
        }
    }

    attachInterrupt(pin, userFunc, m);    
}

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
        case PinMode::Read: {
            pinMode(pin, INPUT);
            break;
        }
        case PinMode::Write: { 
            pinMode(pin, OUTPUT);
            break;
        }
    }
}