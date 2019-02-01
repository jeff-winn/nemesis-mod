#include "Potentiometer.h"

void Potentiometer::init(uint8_t pin) {
    m_pin = createPin(pin);
}

int Potentiometer::read() {
    return m_pin->read();
}

AnalogPin* Potentiometer::createPin(uint8_t pin) {
    AnalogPin* newPin = new AnalogPin(pin);
    newPin->setInputMode();
    
    return newPin;
}