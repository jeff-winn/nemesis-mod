#include <Arduino.h>
#include "Pin.h"

Pin::Pin(uint32_t id) {
    m_Id = id;
}

void Pin::setOutputMode() {
    pinMode(m_Id, OUTPUT);
}