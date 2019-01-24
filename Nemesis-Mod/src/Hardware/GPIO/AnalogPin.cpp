#include <Arduino.h>
#include <stdint.h>
#include "AnalogPin.h"
#include "Pin.h"

AnalogPin::AnalogPin(uint8_t id) : Pin(id) {
}

void AnalogPin::write(uint32_t value) {
    analogWrite(m_Id, value);
}

int AnalogPin::read() {
    return analogRead(m_Id);
}