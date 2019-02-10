#include "Potentiometer.h"

Potentiometer::Potentiometer(AnalogPin* pin) {
    m_pin = pin;
}

float Potentiometer::read() {
    return (float)m_pin->read() / 1024;
}