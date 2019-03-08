#include <Arduino.h>
#include <ArduinoLowPower.h>
#include "Mainboard.h"

void Mainboard::attachInterruptSafe(uint8_t pin, InterruptCallback callback, InterruptMode mode, bool wakeDeviceOnInterrupt) {
    uint32_t modeId;

    switch (mode) {
        case InterruptMode::Falling: {
            modeId = LOW;
            break;
        }
        case InterruptMode::Rising: {
            modeId = HIGH;
            break;
        }
        case InterruptMode::All: {
            modeId = CHANGE;
            break;
        }
    }

    if (wakeDeviceOnInterrupt) {
        LowPower.attachInterruptWakeup(pin ,callback, modeId);
    }
    else {
        attachInterrupt(digitalPinToInterrupt(pin), callback, modeId);
    }
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
    uint32_t modeId;

    switch (mode) {
        case PinMode::Read: {
            modeId = INPUT;
            break;
        }
        case PinMode::Write: {
            modeId = OUTPUT;
            break;
        }
    }

    pinMode(pin, modeId);
}

void Mainboard::sleep() {
    LowPower.sleep();
}