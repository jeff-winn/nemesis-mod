#include "ConfigurationSettings.h"
#include "FeedController.h"
#include "Mainboard.h"

FeedController Belt = FeedController();

FeedController::FeedController() {
    m_driver = G2HighPowerMotorShield18v17(17, 0, 11, 0, A2);
}

void FeedController::init() {
    m_driver.init();
    m_driver.calibrateCurrentOffset();
    m_driver.disableDriver();

    auto speed = Settings.getPusherSpeed();
    setSpeed(speed);
    
    MCU.delaySafe(1);    
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
        case PusherSpeed::Low: {
            return Settings.getPusherLowSpeed();
        }
        case PusherSpeed::Normal: {
            return Settings.getPusherNormalSpeed();
        }
        case PusherSpeed::Max: {
            return Settings.getPusherMaxSpeed();
        }
    }

    return 0; // Disable the motor (speed could not be determined).
}

int FeedController::calculateStepFromSpeed(int speed) {
    return speed / 4;
}

PusherSpeed FeedController::getSpeed() {
    return m_speed;
}

void FeedController::setSpeed(PusherSpeed speed) {
    m_speed = speed;

    if (isRunning()) {
        updateDriver();
    }
}