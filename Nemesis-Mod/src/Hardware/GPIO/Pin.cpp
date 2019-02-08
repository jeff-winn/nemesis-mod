#include "Pin.h"

Pin::Pin(uint8_t id) {
    m_Id = id;
    hal = new HAL();
}

void Pin::setOutputMode() {
    hal->pinModeSafe(m_Id, PinMode::Write);
}

void Pin::setInputMode() {
    hal->pinModeSafe(m_Id, PinMode::Read);
}