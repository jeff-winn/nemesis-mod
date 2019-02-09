#include "PwmPin.h"

PwmPin::PwmPin(uint8_t id, uint32_t frequency) : Pin(id) {
    m_frequency = frequency;
}

void PwmPin::init() {
    hal->setPwmFrequencySafe(m_Id, m_frequency);
}

void PwmPin::write(uint8_t value) { 
    hal->pwmWriteSafe(m_Id, value);
}