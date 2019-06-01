#include "PolledButton.h"

PolledButton::PolledButton(DigitalPin* pin) {
    m_pin = pin;
}

PolledButton::~PolledButton() {
    m_pin = NULL;
}

void PolledButton::init() {
    m_pin->setInputMode();
}

bool PolledButton::isPressed() {
    return m_pin->read() == 1;
}