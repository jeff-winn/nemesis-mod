#include "InterruptPin.h"
#include <Arduino.h>

InterruptPin::InterruptPin(uint32_t pin, bool setLedOn) {
    m_pin = pin;
    m_setLedOn = setLedOn;
}

void InterruptPin::init() {
    digitalWrite(m_pin, OUTPUT);
}

void InterruptPin::reset() {
    digitalWrite(m_pin, LOW);

    if (m_setLedOn) {
        digitalWrite(LED_RED, LOW);
    }
}

void InterruptPin::set() {
    digitalWrite(m_pin, HIGH);

    if (m_setLedOn) {
        digitalWrite(LED_RED, HIGH);
    }
}