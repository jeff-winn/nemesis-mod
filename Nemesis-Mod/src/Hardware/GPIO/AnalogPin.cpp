#include "AnalogPin.h"

AnalogPin::AnalogPin(uint8_t id, HardwareAccessLayer* p_hal) 
    : Pin(id, p_hal) {
}

void AnalogPin::write(uint32_t value) {
    hardware->analogWriteSafe(m_Id, value);
}

int AnalogPin::read() {
    return hardware->analogReadSafe(m_Id);
}