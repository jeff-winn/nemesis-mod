#include "Potentiometer.h"

void Potentiometer::init(uint8_t pin) {
    m_pin = new AnalogPin(pin);
    m_pin->setInputMode();
}

int Potentiometer::read() {
    return m_pin->read();
}