#include "Button.h"

using namespace App::Hardware;

void Button::init(uint8_t pin, uint8_t intPin, void (*onStateChangedCallback)(void)) {
    m_pin = createPin(pin, intPin, onStateChangedCallback);
}

bool Button::isPressed() {
    return m_pin->read() == 0;
}

InterruptPin* Button::createPin(uint8_t pin, uint8_t intPin, void (*onStateChangedCallback)(void)) {
    InterruptPin* newPin = new InterruptPin(pin, intPin);
    newPin->init(onStateChangedCallback, InterruptMode::All);

    return newPin;
}