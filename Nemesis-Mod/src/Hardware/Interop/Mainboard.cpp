#include <Arduino.h>
#include "Mainboard.h"

void Mainboard::attachInterruptSafe(uint8_t pin, void (*userFunc)(void), InterruptMode mode) {
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

int Mainboard::analogReadSafe(uint8_t pin) {
    return analogRead(pin);
}

void Mainboard::analogWriteSafe(uint8_t pin, uint32_t value) {
    analogWrite(pin, value);
}

int Mainboard::digitalReadSafe(uint8_t pin) {
    return digitalRead(pin);
}

void Mainboard::digitalWriteSafe(uint8_t pin, uint32_t value) {
    digitalWrite(pin, value);
}

void Mainboard::pinModeSafe(uint8_t pin, PinMode mode) {
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

void Mainboard::enableSleepMode() {
}

void Mainboard::wake() {
}

void Mainboard::sleep() {
}