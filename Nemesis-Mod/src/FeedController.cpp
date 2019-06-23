#include "FeedController.h"

FeedController::FeedController(Mainboard* hardware, G2HighPowerMotorShield18v17* driver, ConfigurationSettings* config) {
    m_hardware = hardware;
    m_driver = driver;
    m_config = config;
}

FeedController::~FeedController() {
    m_hardware = NULL;
    m_driver = NULL;
    m_config = NULL;
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
            return m_config->getFeedNormalSpeed();
        }
        case BeltSpeed::High: {
            return m_config->getFeedHighSpeed();
        }
        case BeltSpeed::Max: {
            return m_config->getFeedMaxSpeed();
        }
    }
}

int FeedController::calculateStepFromSpeed(int speed) {
    return speed / 4;
}

void FeedController::setSpeed(BeltSpeed speed) {
    m_speed = speed;
}