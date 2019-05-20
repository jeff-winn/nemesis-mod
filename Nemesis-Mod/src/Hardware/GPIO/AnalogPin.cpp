#include "AnalogPin.h"

void AnalogPin::write(uint32_t value) {
    hardware->analogWriteSafe(m_Id, value);
}

int AnalogPin::read() {
    return hardware->analogReadSafe(m_Id);
}