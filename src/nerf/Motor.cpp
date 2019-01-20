#include <Arduino.h>
#include "Motor.h"

void Motor::init(uint32_t directionPin, uint32_t pwmPin) {
    m_directionPin = directionPin;
    m_pwmPin = pwmPin;

    pinMode(m_directionPin, OUTPUT);
    pinMode(m_pwmPin, OUTPUT);
}

void Motor::start() {
    digitalWrite(m_directionPin, HIGH);
    analogWrite(m_pwmPin, 1);
}

void Motor::stop() {
    digitalWrite(m_directionPin, LOW);
    analogWrite(m_pwmPin, 0);
}