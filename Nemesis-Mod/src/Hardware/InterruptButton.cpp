#include "InterruptButton.h"

InterruptButton::InterruptButton(InterruptPin* pin) {
    m_pin = pin;
}

void InterruptButton::init() {
    m_pin->setInputMode();
}

bool InterruptButton::isPressed() {
    return m_pin->read() == 1;
}