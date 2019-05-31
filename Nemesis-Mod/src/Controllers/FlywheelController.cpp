#include "FlywheelController.h"

// Defines the trim variance amount on the maximum speed per motor.
const float TRIM_VARIANCE_AMOUNT = 0.1;

// Defines the 'normal' viable speed for the flywheel assembly.
const int FLYWHEEL_NORMAL_SPEED = 125;

// Defines the 'medium' speed for the flywheel assembly.
const int FLYWHEEL_MEDIUM_SPEED = 250;

// Defines the 'high' speed for the flywheel assembly.
const int FLYWHEEL_HIGH_SPEED = 400;

FlywheelController::FlywheelController(Mainboard* hardware, DualG2HighPowerMotorShield18v18* driver) {
        m_hardware = hardware;
        m_driver = driver;
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
    m_m1Speed = calculateMotorSpeed(FlywheelMotor::Motor1);
    m_m2Speed = calculateMotorSpeed(FlywheelMotor::Motor2);

    m_driver->enableDrivers();
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
    return speed * TRIM_VARIANCE_AMOUNT;
}

int FlywheelController::determineMotorMaximumSpeed() {
    switch (m_speed) {
        case FlywheelSpeed::Normal: {
            return FLYWHEEL_NORMAL_SPEED;
        }
        case FlywheelSpeed::Medium: {
            return FLYWHEEL_MEDIUM_SPEED;
        }
        case FlywheelSpeed::High: {
            return FLYWHEEL_HIGH_SPEED;
        }
    }

    return 0;
}

float FlywheelController::getMotorSpeedAdjustment(FlywheelMotor motor) {
    switch (motor) {
        case FlywheelMotor::Motor1: {
            return m_m1MotorAdjustment;
        }
        case FlywheelMotor::Motor2: {
            return m_m2MotorAdjustment;
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
            m_m1MotorAdjustment = adjustment;
        }
        case FlywheelMotor::Motor2: {
            m_m2MotorAdjustment = adjustment;
        }
    }
}