#include "FeedController.h"

// Defines the 'normal' speed for the feed controller assembly.
const int FEED_NORMAL_SPEED = 75;

// Defines the 'medium' speed for the feed controller assembly.
const int FEED_MEDIUM_SPEED = 125;

// Defines the 'high' speed for the feed controller assembly.
const int FEED_HIGH_SPEED = 175;

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
        case MotorSpeed::Normal: {
            return FEED_NORMAL_SPEED;
        }
        case MotorSpeed::Medium: {
            return FEED_MEDIUM_SPEED;
        }
        case MotorSpeed::High: {
            return FEED_HIGH_SPEED;
        }
    }
}

int FeedController::calculateStepFromSpeed(int speed) {
    return speed / 4;
}