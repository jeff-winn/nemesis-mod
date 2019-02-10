#include "FlywheelController.h"

// Defines the step increment when the motors are being started.
int MOTOR_STEP_INCREMENT = 2;

// Defines the maximum speed for the motors.
int MOTOR_MAX_SPEED = 400;

FlywheelController::FlywheelController(DualG2HighPowerMotorShield18v18* motorController, Potentiometer* pot1, Potentiometer* pot2) {
    m_motorController = motorController;
    m_pot1 = pot1;
    m_pot2 = pot2;
}

void FlywheelController::init() {
    m_motorController->init();
    m_motorController->calibrateCurrentOffsets();

    delay(1);    
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