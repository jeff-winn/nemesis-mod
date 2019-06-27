#include <stddef.h>
#include "FlywheelController.h"

FlywheelController::FlywheelController(Mainboard* hardware, DualG2HighPowerMotorShield18v18* driver, ConfigurationSettings* config) {
    m_hardware = hardware;
    m_driver = driver;
    m_config = config;
}

FlywheelController::~FlywheelController() {
    m_hardware = NULL;
    m_driver = NULL;
    m_config = NULL;
}

void FlywheelController::init() {
    m_driver->init();
    m_driver->calibrateCurrentOffsets();
    m_driver->disableDrivers();

    m_hardware->delaySafe(1);
}

unsigned int FlywheelController::getMotorCurrentMilliamps(FlywheelMotor motor) {
    switch (motor) {
        case FlywheelMotor::Motor1: {
            return m_driver->getM1CurrentMilliamps();
        }
        case FlywheelMotor::Motor2: {
            return m_driver->getM2CurrentMilliamps();
        }
    }

    return 0;
}

void FlywheelController::onStart() {
    m_driver->enableDrivers();
    updateDrivers();
}

void FlywheelController::updateDrivers() {
    m_m1Speed = calculateMotorSpeed(FlywheelMotor::Motor1);
    m_m2Speed = calculateMotorSpeed(FlywheelMotor::Motor2);
    m_driver->setSpeeds(m_m1Speed, m_m2Speed);
    
    m_hardware->delaySafe(1);
}

int FlywheelController::calculateStepFromValue(int value) {
    return value / 4;
}

int FlywheelController::calculateMotorSpeed(FlywheelMotor motor) {
    auto maximumSpeed = determineMotorMaximumSpeed();
    
    auto limiter = calculateLimiterForSpeed(maximumSpeed);
    auto adjustment = getMotorSpeedAdjustment(motor);
    
    return (maximumSpeed - limiter) + (limiter * adjustment);
}

int FlywheelController::calculateLimiterForSpeed(int speed) {
    return speed * m_config->getFlywheelTrimVariance();
}

int FlywheelController::determineMotorMaximumSpeed() {
    switch (m_speed) {
        case FlywheelSpeed::Normal: {
            return m_config->getFlywheelNormalSpeed();
        }
        case FlywheelSpeed::Medium: {
            return m_config->getFlywheelMediumSpeed();
        }
        case FlywheelSpeed::Max: {
            return m_config->getFlywheelMaxSpeed();
        }
    }

    return 0;
}

float FlywheelController::getMotorSpeedAdjustment(FlywheelMotor motor) {
    switch (motor) {
        case FlywheelMotor::Motor1: {
            return m_config->getFlywheelM1TrimAdjustment();
        }
        case FlywheelMotor::Motor2: {
            return m_config->getFlywheelM2TrimAdjustment();
        }
    }

    return 1;
}

void FlywheelController::onStop() {
    auto min = min(m_m1Speed, m_m2Speed);
    auto step = calculateStepFromValue(min);

    m_driver->setSpeeds(0, 0);
    m_driver->disableDrivers();

    m_hardware->delaySafe(1);
    m_m1Speed = 0;
    m_m2Speed = 0;
}

void FlywheelController::setSpeed(FlywheelSpeed speed) {
    m_speed = speed;
}

void FlywheelController::setMotorSpeedAdjustment(FlywheelMotor motor, float adjustment) {
    if (adjustment < 0) {
        return;
    }
    
    switch (motor) {
        case FlywheelMotor::Motor1: {
            m_config->setFlywheelM1TrimAdjustment(adjustment);
            break;
        }
        case FlywheelMotor::Motor2: {
            m_config->setFlywheelM2TrimAdjustment(adjustment);
            break;
        }
    }

    if (isRunning()) {
        updateDrivers();
    }
}