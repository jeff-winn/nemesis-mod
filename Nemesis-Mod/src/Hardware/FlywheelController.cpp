#include "FlywheelController.h"

void FlywheelController::init(FlywheelMotor flywheel, uint8_t pwmPin) {
    switch (flywheel) {
        case FlywheelMotor::Motor1: {
            m_motor1 = new Motor();
            m_motor1->init(pwmPin);
            break;
        }
        case FlywheelMotor::Motor2: {
            m_motor2 = new Motor();
            m_motor2->init(pwmPin);
            break;
        }
    }
}

void FlywheelController::startAll() {
    m_motor1->start();
    m_motor2->start();
}

void FlywheelController::stopAll() {
    m_motor1->stop();
    m_motor2->stop();
}