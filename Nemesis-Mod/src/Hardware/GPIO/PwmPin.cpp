#include "PwmPin.h"

PwmPin::PwmPin(uint8_t id) : Pin(id) {
}

void PwmPin::init(uint32_t frequency) {
    SetPinFrequency(m_id, frequency);
    m_frequency = frequency;
}

void PwmPin::write(uint8_t value) { 
    pwmWrite(m_Id, value);
}