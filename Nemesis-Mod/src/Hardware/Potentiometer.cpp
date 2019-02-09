#include "Potentiometer.h"

Potentiometer::Potentiometer(AnalogPin* pin) {
    m_pin = pin;
}

int Potentiometer::read() {
    return m_pin->read() / 4;
}