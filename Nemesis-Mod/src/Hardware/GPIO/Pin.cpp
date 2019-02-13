#include "Pin.h"

Pin::Pin(uint8_t id, HAL* p_hal) {
    m_Id = id;
    hal = p_hal;
}

void Pin::setOutputMode() {
    hal->pinModeSafe(m_Id, PinMode::Write);
}

void Pin::setInputMode() {
    hal->pinModeSafe(m_Id, PinMode::Read);
}