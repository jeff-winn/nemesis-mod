#include "FlywheelController.h"

void FlywheelController::init(FlywheelMotor flywheel, uint32_t in1, uint32_t in2, MotorDirection direction) {
    switch (flywheel) {
        case FlywheelMotor::Motor1: {
            m_motor1 = new Motor();

            m_motor1->init(in1, in2);
            m_motor1->setDirection(direction);
            break;
        }
        case FlywheelMotor::Motor2: {
            m_motor2 = new Motor();

            m_motor2->init(in1, in2);
            m_motor2->setDirection(direction);
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