#include "FeedController.h"
#include "Log.h"
#include "Mainboard.h"

FeedController Belt = FeedController();

FeedController::FeedController() {
    m_driver = G2HighPowerMotorShield18v17(17, -1, 7, -1, A2);
}

void FeedController::init(ConfigurationSettings* settings) {
    m_driver.init();
    m_driver.calibrateCurrentOffset();
    m_driver.disableDriver();

    m_normalSpeed = settings->getFeedNormalSpeed();
    m_mediumSpeed = settings->getFeedMediumSpeed();
    m_maxSpeed = settings->getFeedMaxSpeed();

    MCU.delaySafe(1);    
    Log.println("Completed initializing feed controller.");
}

unsigned int FeedController::getMotorCurrentMilliamps() {
    return m_driver.getCurrentMilliamps();
}

void FeedController::onStart() {
    m_driver.enableDriver();
    updateDriver();
}

void FeedController::updateDriver() {
    m_m1speed = calculateMotorSpeed();
    m_driver.setSpeed(m_m1speed);

    MCU.delaySafe(1);    
}

void FeedController::onStop() {
    auto step = calculateStepFromSpeed(m_m1speed);

    m_driver.setSpeed(0);   
    m_driver.disableDriver();
    
    MCU.delaySafe(1);
    m_m1speed = 0;
}

int FeedController::calculateMotorSpeed() {
    switch (m_speed) {
        case BeltSpeed::Normal: {
            return m_normalSpeed;
        }
        case BeltSpeed::Medium: {
            return m_mediumSpeed;
        }
        case BeltSpeed::Max: {
            return m_maxSpeed;
        }
    }
}

int FeedController::calculateStepFromSpeed(int speed) {
    return speed / 4;
}

BeltSpeed FeedController::getSpeed() {
    return m_speed;
}

void FeedController::setSpeed(BeltSpeed speed) {
    m_speed = speed;

    if (isRunning()) {
        updateDriver();
    }

    Log.println("Feed speed changed.");   
}