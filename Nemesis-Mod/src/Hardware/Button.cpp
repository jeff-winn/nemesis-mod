#include "Button.h"
#include "GPIO/DigitalPin.h"

void Button::init(uint32_t pin) {
    m_pin = new DigitalPin(pin);
}

bool Button::isPressed() {
    return m_pin->read() == 0;
}