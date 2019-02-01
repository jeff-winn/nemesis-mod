#include "Motor.h"

using namespace App::Hardware;

void Motor::init(uint8_t pin, uint32_t frequency) {
    m_pin = new PwmPin(pin);
    m_pin->init(frequency);
    m_pin->setOutputMode();
}

void Motor::start(uint8_t dutyCycle) {
    if (m_started && m_dutyCycle == dutyCycle) {
        return;
    }

    m_pin->write(dutyCycle);
    m_started = true;
}

void Motor::stop() {
    if (!m_started) {
        return;
    }
    
    m_pin->write(0);
    m_started = false;
}