#include "AnalogPin.h"

using namespace App::Hardware::GPIO;

AnalogPin::AnalogPin(uint8_t id) : Pin(id) {
}

void AnalogPin::write(uint32_t value) {
    hal->analogWriteSafe(m_Id, value);
}

int AnalogPin::read() {
    return hal->analogReadSafe(m_Id);
}