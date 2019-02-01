#include "Pin.h"

using namespace App::Hardware::GPIO;

Pin::Pin(uint8_t id) {
    m_Id = id;
    hal = new HAL();
}

void Pin::setOutputMode() {
    hal->pinModeSafe(m_Id, PinMode::Output);
}

void Pin::setInputMode() {
    hal->pinModeSafe(m_Id, PinMode::Input);
}