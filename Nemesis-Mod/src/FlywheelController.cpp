#include <DualG2HighPowerMotorShield.h>
#include <stddef.h>
#include "ConfigurationSettings.h"
#include "FlywheelController.h"
#include "Log.h"
#include "Mainboard.h"

FlywheelController Flywheels = FlywheelController();

// Defines the driver which controls the flywheel motors.
DualG2HighPowerMotorShield18v18 flywheelDriver = DualG2HighPowerMotorShield18v18(31, -1, 27, -1, A0, 11, -1, 30, -1, A1);

void FlywheelController::init() {
    flywheelDriver.init();
    flywheelDriver.calibrateCurrentOffsets();
    flywheelDriver.disableDrivers();

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

    m_running = true;
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
    return speed * Settings.getFlywheelTrimVariance();
}

int FlywheelController::determineMotorMaximumSpeed() {
    switch (m_speed) {
        case FlywheelSpeed::Normal: {
            return Settings.getFlywheelNormalSpeed();
        }
        case FlywheelSpeed::Medium: {
            return Settings.getFlywheelMediumSpeed();
        }
        case FlywheelSpeed::Max: {
            return Settings.getFlywheelMaxSpeed();
        }
    }

    return 0;
}

float FlywheelController::getMotorSpeedAdjustment(FlywheelMotor motor) {
    switch (motor) {
        case FlywheelMotor::Motor1: {
            return Settings.getFlywheelM1TrimAdjustment();
        }
        case FlywheelMotor::Motor2: {
            return Settings.getFlywheelM2TrimAdjustment();
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
    m_running = false;
}

FlywheelSpeed FlywheelController::getSpeed() {
    return m_speed;
}

void FlywheelController::setSpeed(FlywheelSpeed speed) {
    m_speed = speed;

    if (m_running) {
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
            Settings.setFlywheelM1TrimAdjustment(adjustment);
            break;
        }
        case FlywheelMotor::Motor2: {
            Log.println("Changed M2 trim speed adjustment.");
            Settings.setFlywheelM2TrimAdjustment(adjustment);
            break;
        }
    }

    if (isRunning()) {
        updateDrivers();
    }
}