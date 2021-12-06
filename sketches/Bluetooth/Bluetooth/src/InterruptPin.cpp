#include "InterruptPin.h"
#include <Arduino.h>

InterruptPin::InterruptPin(uint32_t pin) {
    m_pin = pin;
}

InterruptPin::~InterruptPin() {    
}

void InterruptPin::init() {
    pinMode(m_pin, OUTPUT);
}

void InterruptPin::reset() {
    digitalWrite(m_pin, LOW);
}

void InterruptPin::set() {
    digitalWrite(m_pin, HIGH);
}