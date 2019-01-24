#include <Arduino.h>
#include "Motor.h"

void Motor::init(uint32_t pin) {
    m_in1Pin = new DigitalPin(pin);
    m_in1Pin->setOutputMode();
}

void Motor::start() {
    if (m_started) {
        return;
    }

    m_in1Pin->write(HIGH);
    m_started = true;
}

void Motor::stop() {
    if (!m_started) {
        return;
    }
    
    m_in1Pin->write(LOW);
    m_started = false;
}