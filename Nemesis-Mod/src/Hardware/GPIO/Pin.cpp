#include "Pin.h"

Pin::Pin(uint8_t id, HardwareAccessLayer* p_hal) {
    m_Id = id;
    hardware = p_hal;
}

void Pin::setOutputMode() {
    hardware->pinModeSafe(m_Id, PinMode::Write);
}

void Pin::setInputMode() {
    hardware->pinModeSafe(m_Id, PinMode::Read);
}