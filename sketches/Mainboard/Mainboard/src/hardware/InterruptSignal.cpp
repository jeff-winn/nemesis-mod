#include <Arduino.h>
#include "InterruptSignal.h"

InterruptSignal::InterruptSignal(uint32_t pin) {    
    m_pin = pin;
}

InterruptSignal::~InterruptSignal() {
}

void InterruptSignal::init() {
    pinMode(m_pin, INPUT_PULLDOWN);
}

bool InterruptSignal::isSet() {
    return digitalRead(m_pin) != LOW;
}