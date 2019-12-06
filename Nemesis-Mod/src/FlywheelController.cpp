#include <DualG2HighPowerMotorShield.h>
#include <stddef.h>
#include "FlywheelController.h"
#include "Log.h"
#include "Mainboard.h"

FlywheelController Flywheels = FlywheelController();

// Defines the driver which controls the flywheel motors.
DualG2HighPowerMotorShield18v18 flywheelDriver = DualG2HighPowerMotorShield18v18(31, -1, 27, -1, A0, 11, -1, 30, -1, A1);

void FlywheelController::init(ConfigurationSettings* settings) {
    flywheelDriver.init();
    flywheelDriver.calibrateCurrentOffsets();
    flywheelDriver.disableDrivers();

    m_normalSpeed = settings->getFlywheelNormalSpeed();
    m_mediumSpeed = settings->getFlywheelMediumSpeed();
    m_maxSpeed = settings->getFlywheelMaxSpeed();
    m_trimVariance = settings->getFlywheelTrimVariance();
    m_m1TrimAdjustment = settings->getFlywheelM1TrimAdjustment();
    m_m2TrimAdjustment = settings->getFlywheelM2TrimAdjustment();

    MCU.delaySafe(1);
    Log.println("Completed initializing flywheel controller.");
}

unsigned int FlywheelController::getMotorCurrentMilliamps(FlywheelMotor motor) {
    switch (motor) {
        case FlywheelMotor::Motor1: {
            return flywheelDriver.getM1CurrentMilliamps();
        }
        case FlywheelMotor::Motor2: {
            return flywheelDriver.getM2CurrentMilliamps();
        }
    }

    return 0;
}

void FlywheelController::onStart() {
    flywheelDriver.enableDrivers();
    updateDrivers();
}

void FlywheelController::updateDrivers() {
    m_m1Speed = calculateMotorSpeed(FlywheelMotor::Motor1);
    m_m2Speed = calculateMotorSpeed(FlywheelMotor::Motor2);
    flywheelDriver.setSpeeds(m_m1Speed, m_m2Speed);
    
    MCU.delaySafe(1);
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
    return speed * m_trimVariance;
}

int FlywheelController::determineMotorMaximumSpeed() {
    switch (m_speed) {
        case FlywheelSpeed::Normal: {
            return m_normalSpeed;
        }
        case FlywheelSpeed::Medium: {
            return m_mediumSpeed;
        }
        case FlywheelSpeed::Max: {
            return m_maxSpeed;
        }
    }

    return 0;
}

float FlywheelController::getMotorSpeedAdjustment(FlywheelMotor motor) {
    switch (motor) {
        case FlywheelMotor::Motor1: {
            return m_m1TrimAdjustment;
        }
        case FlywheelMotor::Motor2: {
            return m_m2TrimAdjustment;
        }
    }

    return 1;
}

void FlywheelController::onStop() {
    auto minimum = min(m_m1Speed, m_m2Speed);
    auto step = calculateStepFromValue(minimum);

    flywheelDriver.setSpeeds(0, 0);
    flywheelDriver.disableDrivers();

    MCU.delaySafe(1);
    m_m1Speed = 0;
    m_m2Speed = 0;
}

FlywheelSpeed FlywheelController::getSpeed() {
    return m_speed;
}

void FlywheelController::setSpeed(FlywheelSpeed speed) {
    m_speed = speed;

    if (isRunning()) {
        updateDrivers();
    }

    Log.println("Flywheel speed changed.");
}

void FlywheelController::setMotorSpeedAdjustment(FlywheelMotor motor, float adjustment) {
    if (adjustment < 0) {
        return;
    }

    Log.println(adjustment);

    switch (motor) {
        case FlywheelMotor::Motor1: {
            Log.println("Changed M1 trim speed adjustment.");
            m_m1TrimAdjustment = adjustment;
            break;
        }
        case FlywheelMotor::Motor2: {
            Log.println("Changed M2 trim speed adjustment.");
            m_m2TrimAdjustment = adjustment;
            break;
        }
    }

    if (isRunning()) {
        updateDrivers();
    }
}