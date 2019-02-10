#include "FlywheelController.h"

// Defines the step increment when the motors are being started.
int MOTOR_STEP_INCREMENT = 2;

// Defines the maximum speed for the motors.
int MOTOR_MAX_SPEED = 400;

FlywheelController::FlywheelController(DualG2HighPowerMotorShield18v18* motorController) {
    m_motorController = motorController;
}

void FlywheelController::init() {
    m_motorController->init();
    m_motorController->calibrateCurrentOffsets();

    delay(1);    
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
    for (int speed = 0; speed <= MOTOR_MAX_SPEED; speed = speed + MOTOR_STEP_INCREMENT) {
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