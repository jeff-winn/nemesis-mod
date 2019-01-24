#include "Button.h"
#include "GPIO/DigitalPin.h"

void Button::init(uint8_t pin) {
    m_pin = new DigitalPin(pin);
}

bool Button::isPressed() {
    return m_pin->read() == 0;
}