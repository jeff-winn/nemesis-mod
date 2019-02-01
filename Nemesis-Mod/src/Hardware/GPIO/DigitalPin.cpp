#include "DigitalPin.h"

using namespace App::Hardware::GPIO;

DigitalPin::DigitalPin(uint8_t id) : Pin(id) {
}

void DigitalPin::write(uint32_t value) {
    hal->digitalWriteSafe(m_Id, value);
}

int DigitalPin::read() {
    return hal->digitalReadSafe(m_Id);
}