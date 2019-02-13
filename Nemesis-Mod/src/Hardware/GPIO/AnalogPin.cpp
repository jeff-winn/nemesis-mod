#include "AnalogPin.h"

AnalogPin::AnalogPin(uint8_t id, HAL* p_hal) 
    : Pin(id, p_hal) {
}

void AnalogPin::write(uint32_t value) {
    hal->analogWriteSafe(m_Id, value);
}

int AnalogPin::read() {
    return hal->analogReadSafe(m_Id);
}