#include <Arduino.h>
#include "Pin.h"

void Pin::setOutputMode() {
    pinMode(m_Id, OUTPUT);
}

Pin::Pin(uint32_t id) {
    m_Id = id;
}