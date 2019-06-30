#include "Button.h"

Button::Button(DigitalPin* pin, bool inverted) {
    m_pin = pin;
    m_inverted = inverted;
}

Button::~Button() {
    m_pin = NULL;
}

void Button::init() {
    m_pin->setInputMode();
}

bool Button::isPressed() {
    auto value = m_pin->read();
    if (m_inverted) {
        return !value;
    }
    
    return value;
}