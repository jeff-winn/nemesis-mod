#include <Arduino.h>
#include <stdint.h>
#include "DigitalPin.h"
#include "Pin.h"

DigitalPin::DigitalPin(uint8_t id) : Pin(id) {
}

void DigitalPin::write(uint32_t value) {
    digitalWrite(m_Id, value);
}

int DigitalPin::read() {
    return digitalRead(m_Id);
}