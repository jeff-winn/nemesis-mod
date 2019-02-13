#include "DigitalPin.h"

DigitalPin::DigitalPin(uint8_t id, HAL* p_hal) 
    : Pin(id, p_hal) {
}

void DigitalPin::write(uint32_t value) {
    hal->digitalWriteSafe(m_Id, value);
}

bool DigitalPin::read() {
    return hal->digitalReadSafe(m_Id) != 0;
}