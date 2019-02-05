#include "FlywheelController.h"

void FlywheelController::init(FlywheelMotor flywheel, uint8_t pwm, uint8_t pot) {
    switch (flywheel) {        
        case FlywheelMotor::Motor1: {
            m_motorController1 = createMotorController(pwm, pot);
            break;
        }
        case FlywheelMotor::Motor2: {
            m_motorController2 = createMotorController(pwm, pot);
            break;
        }
    }
}

void FlywheelController::start() {
    m_motorController1->start();
    m_motorController2->start();
}

void FlywheelController::stop() {
    m_motorController1->stop();
    m_motorController2->stop();
}

MotorController* FlywheelController::createMotorController(uint8_t pwm, uint8_t pot) {
    MotorController* newController = new MotorController();
    newController->init(pwm, pot);

    return newController;
}