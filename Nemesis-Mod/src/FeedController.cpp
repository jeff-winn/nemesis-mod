#include "hardware/G2HighPowerMotorShield.h"
#include "hardware/Mainboard.h"
#include "ConfigurationSettings.h"
#include "FeedController.h"
#include "Log.h"

FeedController Belt = FeedController();

// Defines the driver which controls the belt feed motor.
G2HighPowerMotorShield18v17 beltDriver = G2HighPowerMotorShield18v17(17, -1, 7, -1, A2);

void FeedController::init() {
    beltDriver.init();
    beltDriver.calibrateCurrentOffset();
    beltDriver.disableDriver();

    MCU.delaySafe(1);    
    Log.println("Completed initializing feed controller.");
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
            return Settings.getFeedNormalSpeed();
        }
        case BeltSpeed::High: {
            return Settings.getFeedHighSpeed();
        }
        case BeltSpeed::Max: {
            return Settings.getFeedMaxSpeed();
        }
    }
}

int FeedController::calculateStepFromSpeed(int speed) {
    return speed / 4;
}

void FeedController::setSpeed(BeltSpeed speed) {
    m_speed = speed;
    Log.println("Feed speed changed.");   
}