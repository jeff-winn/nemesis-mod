#include "InterruptButton.h"

InterruptButton::InterruptButton(InterruptPin* pin) {
    m_pin = pin;
}

void InterruptButton::init(void (*onStateChangedCallback)(void)) {
    m_pin->setInputMode();
    m_pin->init(onStateChangedCallback, InterruptMode::All);
}

bool InterruptButton::isPressed() {
    return m_pin->read() == 1;
}