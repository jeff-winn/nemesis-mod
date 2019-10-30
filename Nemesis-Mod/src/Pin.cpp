#include <stddef.h>
#include "Pin.h"

Pin::Pin(uint32_t id, Mainboard* hal) {
    m_Id = id;
    hardware = hal;
}

Pin::~Pin() {
    hardware = NULL;
}

void Pin::setOutputMode() {
    hardware->pinModeSafe(m_Id, PinMode::Write);
}

void Pin::setInputMode() {
    hardware->pinModeSafe(m_Id, PinMode::Read);
}