#include "InterruptButton.h"

InterruptButton::InterruptButton(InterruptPin* pin) {
    m_pin = pin;
}

void InterruptButton::init(void (*onStateChangedCallback)(void)) {
    m_pin->init(onStateChangedCallback, InterruptMode::All);
    m_pin->setInputMode();
}

bool InterruptButton::isPressed() {
    return m_pin->read() == 1;
}