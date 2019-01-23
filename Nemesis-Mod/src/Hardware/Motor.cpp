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

    switch (m_direction) {
        case MotorDirection::Forward: {
            m_in1Pin->write(LOW);
            m_in2Pin->write(HIGH);
            break;
        }
        case MotorDirection::Reverse: {
            m_in1Pin->write(HIGH);
            m_in2Pin->write(LOW);
            break;
        }
    }

    m_started = true;
}

void Motor::setDirection(MotorDirection direction) {
    m_direction = direction;
}

void Motor::stop() {
    if (!m_started) {
        return;
    }
    
    m_in1Pin->write(LOW);
    m_in2Pin->write(LOW);

    m_started = false;
}