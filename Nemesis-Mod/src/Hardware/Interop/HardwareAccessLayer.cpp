#include <Arduino.h>
#include "HardwareAccessLayer.h"

void HardwareAccessLayer::attachInterruptSafe(uint8_t pin, void (*userFunc)(void), InterruptMode mode) {
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

int HardwareAccessLayer::analogReadSafe(uint8_t pin) {
    return analogRead(pin);
}

void HardwareAccessLayer::analogWriteSafe(uint8_t pin, uint32_t value) {
    analogWrite(pin, value);
}

int HardwareAccessLayer::digitalReadSafe(uint8_t pin) {
    return digitalRead(pin);
}

void HardwareAccessLayer::digitalWriteSafe(uint8_t pin, uint32_t value) {
    digitalWrite(pin, value);
}

void HardwareAccessLayer::pinModeSafe(uint8_t pin, PinMode mode) {
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

void HardwareAccessLayer::enableSleepMode() {
}

void HardwareAccessLayer::disableSleepMode() {
}

void HardwareAccessLayer::sleep() {
}