#include "InterruptButton.h"

InterruptButton::InterruptButton(InterruptPin* pin) {
    m_pin = pin;
}

InterruptButton::~InterruptButton() {
    m_pin = NULL;
}

void InterruptButton::init() {
    m_pin->init();
    m_pin->setInputMode();
}

bool InterruptButton::isPressed() {
    return m_pin->read() == 0;
}