#include "Motor.h"

void Motor::init(uint8_t pin, uint32_t frequency) {
    m_pin = createPin(pin, frequency);
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

PwmPin* Motor::createPin(uint8_t pin, uint32_t frequency) {
    PwmPin* newPin = new PwmPin(pin);
    newPin->init(frequency);
    newPin->setOutputMode();

    return newPin;
}