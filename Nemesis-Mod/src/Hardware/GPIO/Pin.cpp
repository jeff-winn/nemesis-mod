#include <Arduino.h>
#include "Pin.h"

Pin::Pin(uint8_t id) {
    m_Id = id;
}

void Pin::setOutputMode() {
    pinMode(m_Id, OUTPUT);
}

void Pin::setInputMode() {
    pinMode(m_Id, INPUT);
}