#include "Button.h"

void Button::init(uint8_t pin, uint8_t intPin, void (*onStateChangedCallback)(void)) {
    m_pin = new InterruptPin(pin, intPin);
    m_pin->init(onStateChangedCallback, InterruptMode::All);
}

bool Button::isPressed() {
    return m_pin->read() == 0;
}