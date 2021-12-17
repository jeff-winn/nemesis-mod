#include "PusherController.h"

#include "ConfigurationSettings.h"
#include "Mainboard.h"

PusherController Pusher = PusherController();

PusherController::PusherController() {
    m_driver = G2HighPowerMotorShield18v17(17, 0, 11, 0, A2);
}

void PusherController::init() {
    m_driver.init();
    m_driver.calibrateCurrentOffset();
    m_driver.disableDriver();

    auto speed = Settings.getPusherSpeed();
    setSpeed(speed);
    
    MCU.delaySafe(1);    
}

unsigned int PusherController::getMotorCurrentMilliamps() {
    return m_driver.getCurrentMilliamps();
}

void PusherController::onStart() {
    m_driver.enableDriver();
    updateDriver();
}

void PusherController::updateDriver() {
    m_m1speed = calculateMotorSpeed();
    m_driver.setSpeed(m_m1speed);

    MCU.delaySafe(1);    
}

void PusherController::onStop() {
    auto step = calculateStepFromSpeed(m_m1speed);

    m_driver.setSpeed(0);   
    m_driver.disableDriver();
    
    MCU.delaySafe(1);
    m_m1speed = 0;
}

int PusherController::calculateMotorSpeed() {
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

int PusherController::calculateStepFromSpeed(int speed) {
    return speed / 4;
}

PusherSpeed PusherController::getSpeed() {
    return m_speed;
}

void PusherController::setSpeed(PusherSpeed speed) {
    m_speed = speed;

    if (isRunning()) {
        updateDriver();
    }
}