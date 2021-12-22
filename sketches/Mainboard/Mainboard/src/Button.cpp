#include "Button.h"

#include "Mainboard.h"

Button::Button(uint32_t pin, bool inverted) {
    m_pin = pin;
    m_inverted = inverted;
}

Button::~Button() {
}

void Button::init() const {
    MCU.pinModeSafe(m_pin, PinMode::Read);    
}

bool Button::isPressed() const {    
    auto value = MCU.digitalReadSafe(m_pin);
    if (m_inverted) {
        return !value;
    }
    
    return value;
}