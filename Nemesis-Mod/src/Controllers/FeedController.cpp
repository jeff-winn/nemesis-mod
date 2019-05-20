#include "FeedController.h"

// Defines the 'low' viable speed for the feed controller assembly.
const int MOTOR_LOW_SPEED = 100;

// Defines the 'normal' speed for the feed controller assembly.
const int MOTOR_NORMAL_SPEED = 200;

// Defines the 'high' speed for the feed controller assembly.
const int MOTOR_HIGH_SPEED = 400;

FeedController::FeedController(Mainboard* hardware, G2HighPowerMotorShield18v17* driver) {
    m_hardware = hardware;
    m_driver = driver;
}

void FeedController::init() {
    m_driver->init();
    m_driver->calibrateCurrentOffset();
    m_driver->disableDriver();

    m_hardware->delaySafe(1);    
}

void FeedController::onStart() {
    m_speed = calculateMotorSpeed();

    m_driver->enableDriver();
    m_driver->setSpeed(m_speed);

    m_hardware->delaySafe(1);    
}

void FeedController::onStop() {
    auto step = calculateStepFromSpeed(m_speed);

    m_driver->setSpeed(0);   
    m_driver->disableDriver();
    
    m_hardware->delaySafe(1);
    m_speed = 0;
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

int FeedController::calculateStepFromSpeed(int speed) {
    return speed / 4;
}