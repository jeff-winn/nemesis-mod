#include <Arduino.h>
#include "AnalogPin.h"
#include "DigitalPin.h"
#include "Motor.h"

void Motor::init(uint32_t directionPin, uint32_t pwmPin) {
    m_directionPin = new DigitalPin(directionPin);
    m_directionPin->setOutputMode();

    m_pwmPin = new AnalogPin(pwmPin);
    m_pwmPin->setOutputMode();
}

void Motor::start() {
    m_directionPin->write(HIGH);
    m_pwmPin->write(1);
    // digitalWrite(m_directionPin, HIGH);
    // analogWrite(m_pwmPin, 1);
}

void Motor::stop() {
    m_directionPin->write(LOW);
    m_pwmPin->write(0);
    
    // digitalWrite(m_directionPin, LOW);
    // analogWrite(m_pwmPin, 0);
}