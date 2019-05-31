#include "FeedController.h"

// Defines the 'normal' speed for the feed controller assembly.
const int FEED_NORMAL_SPEED = 100;

// Defines the 'high' speed for the feed controller assembly.
const int FEED_HIGH_SPEED = 175;

// Defines the 'maximum' speed for the feed controller assembly.
const int FEED_MAX_SPEED = 400;

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
    m_m1speed = calculateMotorSpeed();

    m_driver->enableDriver();
    m_driver->setSpeed(m_m1speed);

    m_hardware->delaySafe(1);    
}

void FeedController::onStop() {
    auto step = calculateStepFromSpeed(m_m1speed);

    m_driver->setSpeed(0);   
    m_driver->disableDriver();
    
    m_hardware->delaySafe(1);
    m_m1speed = 0;
}

int FeedController::calculateMotorSpeed() {
    switch (m_speed) {
        case BeltSpeed::Normal: {
            return FEED_NORMAL_SPEED;
        }
        case BeltSpeed::Max: {
            return FEED_MAX_SPEED;
        }
    }
}

int FeedController::calculateStepFromSpeed(int speed) {
    return speed / 4;
}

void FeedController::setSpeed(BeltSpeed speed) {
    m_speed = speed;
}