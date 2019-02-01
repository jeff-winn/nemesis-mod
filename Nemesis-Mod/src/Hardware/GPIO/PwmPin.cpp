#include "PwmPin.h"

using namespace App::Hardware::GPIO;

PwmPin::PwmPin(uint8_t id) : Pin(id) {
}

void PwmPin::init(uint32_t frequency) {
    hal->setPwmFrequencySafe(m_Id, frequency);
    m_frequency = frequency;
}

void PwmPin::write(uint8_t value) { 
    hal->pwmWriteSafe(m_Id, value);
}