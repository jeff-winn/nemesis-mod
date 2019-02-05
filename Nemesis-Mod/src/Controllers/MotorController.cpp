#include "MotorController.h"

void MotorController::init(uint8_t pwm, uint8_t pot) {
    m_motor = createMotor(pwm, MOTOR_FREQUENCY);
    m_potentiometer = createPotentiometer(pot);
}

void MotorController::start() {
    uint8_t dutyCycle = m_potentiometer->read() / 4;

    m_motor->start(dutyCycle);
}

void MotorController::stop() {
    m_motor->stop();
}

Motor* MotorController::createMotor(uint8_t pwm, int frequency) {
    Motor* newMotor = new Motor();
    newMotor->init(pwm, frequency);

    return newMotor;
}

Potentiometer* MotorController::createPotentiometer(uint8_t pot) {
    Potentiometer* newPotentiometer = new Potentiometer();
    newPotentiometer->init(pot);

    return newPotentiometer;
}