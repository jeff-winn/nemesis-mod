#include "DigitalPin.h"

DigitalPin::DigitalPin(uint8_t id, Mainboard* hal) 
    : Pin(id, hal) {
}

void DigitalPin::write(uint32_t value) {
    hardware->digitalWriteSafe(m_Id, value);
}

bool DigitalPin::read() {
    return hardware->digitalReadSafe(m_Id) != 0;
}