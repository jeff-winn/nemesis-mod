#include "PolledButton.h"

PolledButton::PolledButton(DigitalPin* pin) {
    m_pin = pin;
}

void PolledButton::init() {
    m_pin->setInputMode();
}

bool PolledButton::isPressed() {
    return m_pin->read() == 1;
}