#include "FlywheelController.h"

void FlywheelController::init(FlywheelMotor flywheel, uint8_t pwm, uint8_t pot) {
    switch (flywheel) {
        case FlywheelMotor::Motor1: {
            m_motor1 = new Motor();
            m_motor1->init(pwm);

            m_potentiometer1 = new Potentiometer();
            m_potentiometer1->init(pot);
            break;
        }
        case FlywheelMotor::Motor2: {
            m_motor2 = new Motor();
            m_motor2->init(pwm);

            m_potentiometer2 = new Potentiometer();
            m_potentiometer2->init(pot);
            break;
        }
    }
}

void FlywheelController::startAll() {
    int dutyCycle1 = m_potentiometer1->read();
    int dutyCycle2 = m_potentiometer2->read();

    m_motor1->start(dutyCycle1);
    m_motor2->start(dutyCycle2);
}

void FlywheelController::stopAll() {
    m_motor1->stop();
    m_motor2->stop();
}