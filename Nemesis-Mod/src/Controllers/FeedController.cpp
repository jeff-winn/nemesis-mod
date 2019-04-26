#include "FeedController.h"

// Defines the 'low' viable speed for the feed controller assembly.
const int MOTOR_LOW_SPEED = 100;

// Defines the 'normal' speed for the feed controller assembly.
const int MOTOR_NORMAL_SPEED = 200;

// Defines the 'high' speed for the feed controller assembly.
const int MOTOR_HIGH_SPEED = 400;

FeedController::FeedController(HardwareAccessLayer* hardware, G2HighPowerMotorShield18v17* motorController, MotorSpeed speed) {
    m_hardware = hardware;
    m_motorController = motorController;
    m_speed = speed;
}

void FeedController::init() {
    m_motorController->init();
    m_motorController->calibrateCurrentOffset();

    m_hardware->delaySafe(1);    
}

void FeedController::onStart() {
    auto speed = calculateMotorSpeed();

    m_motorController->setSpeed(speed);
    m_hardware->delaySafe(1);
}

void FeedController::onStop() {
    m_motorController->setSpeed(0);
    m_hardware->delaySafe(1);
}

int FeedController::calculateMotorSpeed() {
    switch (m_speed) {
        case MotorSpeed::Low: {
            return MOTOR_LOW_SPEED;
        }
        case MotorSpeed::Normal: {
            return MOTOR_NORMAL_SPEED;
        }
        case MotorSpeed::High: {
            return MOTOR_HIGH_SPEED;
        }
    }
}