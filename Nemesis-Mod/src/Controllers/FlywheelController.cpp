#include "FlywheelController.h"

// Defines the step increment when the flywheel assembly is being started.
int FLYWHEEL_STEP_INCREMENT = 2;

// Defines the minimum viable speed for the flywheel assembly.
int FLYWHEEL_MIN_SPEED = 200;

// Defines the intermediate speed for the flywheel assembly.
int FLYWHEEL_INTERMEDIATE_SPEED = 300;

// Defines the maximum speed for the flywheel assembly.
int FLYWHEEL_MAX_SPEED = 400;

FlywheelController::FlywheelController(DualG2HighPowerMotorShield18v18* motorController) {
    m_motorController = motorController;
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
    m_motorController->enableDrivers();
    delay(1);
    
    // Ramp up the motor speed rather than going directly to max power.
    for (int speed = 0; speed <= m_motorSpeed; speed = speed + FLYWHEEL_STEP_INCREMENT) {
        m_motorController->setSpeeds(speed, speed);
        delay(1);
    }
}

void FlywheelController::stop() {
    m_motorController->setSpeeds(0, 0);
    delay(1);
    
    m_motorController->disableDrivers();
    delay(1);
}