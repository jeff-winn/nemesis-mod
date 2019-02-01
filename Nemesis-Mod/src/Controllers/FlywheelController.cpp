#include "FlywheelController.h"

using namespace App::Controllers;
using namespace App::Hardware;

void FlywheelController::init(FlywheelMotor flywheel, uint8_t pwm, uint8_t pot) {
    switch (flywheel) {
        case FlywheelMotor::Motor1: {
            m_motor1 = createMotor(pwm, MOTOR_FREQUENCY);
            m_potentiometer1 = createPotentiometer(pot);
            break;
        }
        case FlywheelMotor::Motor2: {
            m_motor2 = createMotor(pwm, MOTOR_FREQUENCY);
            m_potentiometer2 = createPotentiometer(pot);
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

Motor* FlywheelController::createMotor(uint8_t pwm, int frequency) {
    Motor* newMotor = new Motor();
    newMotor->init(pwm, frequency);

    return newMotor;
}

Potentiometer* FlywheelController::createPotentiometer(uint8_t pot) {
    Potentiometer* newPotentiometer = new Potentiometer();
    newPotentiometer->init(pot);

    return newPotentiometer;
}