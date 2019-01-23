#include "FlywheelController.h"
#include "Motor.h"

void FlywheelController::init(uint32_t in1, uint32_t in2, uint32_t in3, uint32_t in4) {
    m_motor1 = new Motor();
    m_motor1->init(in1, in2);

    m_motor2 = new Motor();
    m_motor2->init(in3, in4);
}

void FlywheelController::setDirection(MotorDirection direction) {
    m_motor1->setDirection(direction);
    m_motor2->setDirection(direction);
}

void FlywheelController::startAll() {
    m_motor1->start();
    m_motor2->start();
}

void FlywheelController::stopAll() {
    m_motor1->stop();
    m_motor2->stop();
}