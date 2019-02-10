#include "Button.h"

Button::Button(InterruptPin* pin) {
    m_pin = pin;
}

void Button::init(void (*onStateChangedCallback)(void)) {
    m_pin->init(onStateChangedCallback, InterruptMode::All);
    m_pin->setInputMode();
}

bool Button::isPressed() {
    return m_pin->read() == 0;
}