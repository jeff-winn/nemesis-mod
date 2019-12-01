#include "hardware/G2HighPowerMotorShield.h"
#include "FeedController.h"
#include "Log.h"
#include "Mainboard.h"

FeedController Belt = FeedController();

// Defines the driver which controls the belt feed motor.
G2HighPowerMotorShield18v17 beltDriver = G2HighPowerMotorShield18v17(17, -1, 7, -1, A2);

void FeedController::init(ConfigurationSettings* settings) {
    beltDriver.init();
    beltDriver.calibrateCurrentOffset();
    beltDriver.disableDriver();

    m_normalSpeed = settings->getFeedNormalSpeed();
    m_mediumSpeed = settings->getFeedMediumSpeed();
    m_maxSpeed = settings->getFeedMaxSpeed();

    MCU.delaySafe(1);    
    Log.println("Completed initializing feed controller.");
}

unsigned int FeedController::getMotorCurrentMilliamps() {
    return beltDriver.getCurrentMilliamps();
}

void FeedController::onStart() {
    m_m1speed = calculateMotorSpeed();

    beltDriver.enableDriver();
    beltDriver.setSpeed(m_m1speed);

    MCU.delaySafe(1);    
}

void FeedController::onStop() {
    auto step = calculateStepFromSpeed(m_m1speed);

    beltDriver.setSpeed(0);   
    beltDriver.disableDriver();
    
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
    Log.println("Feed speed changed.");   
}