#include "FlywheelController.h"

void FlywheelController::init(FlywheelMotor flywheel, uint8_t pwm, uint32_t frequency, uint8_t pot) {
    switch (flywheel) {
        case FlywheelMotor::Motor1: {
            m_motor1 = new Motor();
            m_motor1->init(pwm, frequency);

            m_potentiometer1 = new Potentiometer();
            m_potentiometer1->init(pot);
            break;
        }
        case FlywheelMotor::Motor2: {
            m_motor2 = new Motor();
            m_motor2->init(pwm, frequency);

            m_potentiometer2 = new Potentiometer();
            m_potentiometer2->init(pot);
            break;
        }
    }
}

void FlywheelController::startAll() {
    uint8_t dutyCycle1 = m_potentiometer1->read() / 4;
    uint8_t dutyCycle2 = m_potentiometer2->read() / 4;

    m_motor1->start(dutyCycle1);
    m_motor2->start(dutyCycle2);
}

void FlywheelController::stopAll() {
    m_motor1->stop();
    m_motor2->stop();
}

