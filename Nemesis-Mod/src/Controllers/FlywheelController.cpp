#include "FlywheelController.h"

// Defines the trim variance amount on the maximum speed per motor.
const double TRIM_VARIANCE_AMOUNT = 0.1;

// Defines the step increment when the flywheel assembly is being started.
const int FLYWHEEL_STEP_INCREMENT = 5;

// Defines the 'low' viable speed for the flywheel assembly.
const int FLYWHEEL_LOW_SPEED = 100;

// Defines the 'normal' speed for the flywheel assembly.
const int FLYWHEEL_NORMAL_SPEED = 200;

// Defines the 'high' speed for the flywheel assembly.
const int FLYWHEEL_HIGH_SPEED = 400;

FlywheelController::FlywheelController(
    HardwareAccessLayer* hardware, DualG2HighPowerMotorShield18v18* motorController, Potentiometer* motor1Potentiometer, Potentiometer* motor2Potentiometer, FlywheelSpeed speed) {
        m_hardware = hardware;
        m_motorController = motorController;
        m_motor1Adjustment = motor1Potentiometer;
        m_motor2Adjustment = motor2Potentiometer;
        m_speed = speed;
}

void FlywheelController::init() {
    m_motorController->init();
    m_motorController->calibrateCurrentOffsets();

    m_hardware->delaySafe(1);
}

void FlywheelController::setSpeed(FlywheelSpeed value) {
    m_speed = value;
}

unsigned int FlywheelController::getMotorCurrentMilliamps(FlywheelMotor motor) {
    switch (motor) {
        case FlywheelMotor::Motor1: {
            return m_motorController->getM1CurrentMilliamps();
        }
        case FlywheelMotor::Motor2: {
            return m_motorController->getM2CurrentMilliamps();
        }
    }

    return 0;
}

void FlywheelController::onStart() {
    auto motor1Maximum = calculateMotorSpeed(FlywheelMotor::Motor1);
    auto motor2Maximum = calculateMotorSpeed(FlywheelMotor::Motor2);

    auto maximum = max(motor1Maximum, motor2Maximum);
    auto current = 0;

    m_motorController->setSpeeds(motor1Maximum, motor2Maximum);
    m_hardware->delaySafe(1);
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
        case FlywheelSpeed::Low: {
            return FLYWHEEL_LOW_SPEED;
        }
        case FlywheelSpeed::Normal: {
            return FLYWHEEL_NORMAL_SPEED;
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
            return m_motor1Adjustment->read();
        }
        case FlywheelMotor::Motor2: {
            return m_motor2Adjustment->read();
        }
    }

    return 0;
}

void FlywheelController::onStop() {
    m_motorController->setSpeeds(0, 0);
    m_hardware->delaySafe(1);
}