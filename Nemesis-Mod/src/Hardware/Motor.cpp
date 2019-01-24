#include <Arduino.h>
#include "Motor.h"

void Motor::init(uint32_t in1Pin, uint32_t in2Pin) {
    m_in1Pin = new DigitalPin(in1Pin);
    m_in1Pin->setOutputMode();

    m_in2Pin = new DigitalPin(in2Pin);
    m_in2Pin->setOutputMode();
}

void Motor::start() {
    if (m_started) {
        return;
    }

    m_in1Pin->write(LOW);
    m_in2Pin->write(HIGH);

    m_started = true;
}

void Motor::stop() {
    if (!m_started) {
        return;
    }
    
    m_in1Pin->write(LOW);
    m_in2Pin->write(LOW);

    m_started = false;
}