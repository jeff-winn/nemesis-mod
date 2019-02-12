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

    m_speed = FlywheelSpeed::Low;
}

void FlywheelController::init() {
    m_motorController->init();
    m_motorController->calibrateCurrentOffsets();

    delay(1);    
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

void FlywheelController::start() {
    if (m_isRunning) {
        return;
    }

    m_motorController->enableDrivers();
    delay(1);

    int maximumSpeed = determineMotorSpeed();

    float motor1Adjustment = getMotorSpeedAdjustment(FlywheelMotor::Motor1);
    float motor2Adjustment = getMotorSpeedAdjustment(FlywheelMotor::Motor2);

    // Ramp up the motor speed rather than going directly to max power.
    for (int speed = 0; speed <= maximumSpeed; speed = speed + FLYWHEEL_STEP_INCREMENT) {
        m_motorController->setM1Speed(speed * motor1Adjustment);
        m_motorController->setM2Speed(speed * motor2Adjustment);
                
        delay(2);
    }

    m_isRunning = true;
    delay(500);
}

int FlywheelController::determineMotorSpeed() {
    switch (m_speed) {
        case FlywheelSpeed::Low: {
            return FLYWHEEL_MIN_SPEED;
        }
        case FlywheelSpeed::Medium: {
            return FLYWHEEL_INTERMEDIATE_SPEED;
        }
        case FlywheelSpeed::High: {
            return FLYWHEEL_MAX_SPEED;
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

void FlywheelController::stop() {
    if (!m_isRunning) {
        return;
    }

    m_motorController->setSpeeds(0, 0);   
    m_motorController->disableDrivers();
    delay(1);

    m_isRunning = false;
    delay(500);
}