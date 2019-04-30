#include "FeedController.h"

// Defines the 'low' viable speed for the feed controller assembly.
const int MOTOR_LOW_SPEED = 100;

// Defines the 'normal' speed for the feed controller assembly.
const int MOTOR_NORMAL_SPEED = 150;

// Defines the 'high' speed for the feed controller assembly.
const int MOTOR_HIGH_SPEED = 200;

FeedController::FeedController(HardwareAccessLayer* hardware, G2HighPowerMotorShield18v17* driver) {
    m_hardware = hardware;
    m_driver = driver;
}

void FeedController::init() {
    m_driver->init();
    m_driver->calibrateCurrentOffset();

    m_hardware->delaySafe(1);    
}

void FeedController::onStart() {
    auto speed = calculateMotorSpeed();

    m_driver->setSpeed(speed);
    m_hardware->delaySafe(1);
}

void FeedController::onStop() {
    m_driver->setSpeed(0);
    m_hardware->delaySafe(1);
}

int FeedController::calculateMotorSpeed() {
    auto speed = getSpeed();

    switch (speed) {
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