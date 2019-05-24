#include "PolledButton.h"

PolledButton::PolledButton(DigitalPin* pin) {
    m_pin = pin;
}

bool PolledButton::isPressed() {
    return m_pin->read() == 1;
}