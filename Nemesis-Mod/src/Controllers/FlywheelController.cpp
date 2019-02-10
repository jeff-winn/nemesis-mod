#include "FlywheelController.h"

// Defines the step increment when the flywheel assembly is being started.
int FLYWHEEL_STEP_INCREMENT = 2;

// Defines the minimum viable speed for the flywheel assembly.
int FLYWHEEL_MIN_SPEED = 200;

// Defines the intermediate speed for the flywheel assembly.
int FLYWHEEL_INTERMEDIATE_SPEED = 300;

// Defines the maximum speed for the flywheel assembly.
int FLYWHEEL_MAX_SPEED = 400;

FlywheelController::FlywheelController(
    DualG2HighPowerMotorShield18v18* motorController, Potentiometer* motor1Potentiometer, Potentiometer* motor2Potentiometer) {
    m_motorController = motorController;
    m_motor1Adjustment = motor1Potentiometer;
    m_motor2Adjustment = motor2Potentiometer;

    m_motorSpeed = FLYWHEEL_MIN_SPEED;
}

void FlywheelController::init() {
    m_motorController->init();
    m_motorController->calibrateCurrentOffsets();

    delay(1);    
}

void FlywheelController::setSpeed(FlywheelSpeed speed) {
    switch (speed) {
        case FlywheelSpeed::Level1: {
            m_motorSpeed = FLYWHEEL_MIN_SPEED;
            break;
        }
        case FlywheelSpeed::Level2: {
            m_motorSpeed = FLYWHEEL_INTERMEDIATE_SPEED;
            break;
        }
        case FlywheelSpeed::Level3: {
            m_motorSpeed = FLYWHEEL_MAX_SPEED;
            break;
        }
    }
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

void FlywheelController::start() {
    if (m_isRunning) {
        return;
    }

    m_motorController->enableDrivers();
    delay(1);

    float motor1Adjustment = getMotorSpeedAdjustment(FlywheelMotor::Motor1);
    float motor2Adjustment = getMotorSpeedAdjustment(FlywheelMotor::Motor2);

    // Ramp up the motor speed rather than going directly to max power.
    for (int speed = 0; speed <= m_motorSpeed; speed = speed + FLYWHEEL_STEP_INCREMENT) {
        m_motorController->setSpeeds(speed * motor1Adjustment, speed * motor2Adjustment);
        delay(1);
    }

    m_isRunning = true;
}

float FlywheelController::getMotorSpeedAdjustment(FlywheelMotor motor) {
    int value = 0;
    switch (motor) {
        case FlywheelMotor::Motor1: {
            value = m_motor1Adjustment->read();
            break;
        }
        case FlywheelMotor::Motor2: {
            value = m_motor2Adjustment->read();
            break;
        }
    }

    return (float)value / 255;
}

void FlywheelController::stop() {
    if (!m_isRunning) {
        return;
    }

    m_motorController->setSpeeds(0, 0);
    delay(1);
    
    m_motorController->disableDrivers();
    delay(1);

    m_isRunning = false;
}