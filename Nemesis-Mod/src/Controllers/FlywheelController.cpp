#include "FlywheelController.h"

FlywheelController::FlywheelController(DualG2HighPowerMotorShield18v18* motorController, Potentiometer* pot1, Potentiometer* pot2) {
    m_motorController = motorController;
    m_pot1 = pot1;
    m_pot2 = pot2;
}

void FlywheelController::init() {
    m_motorController->enableDrivers();
    m_motorController->init();
}

void FlywheelController::start() {
    
}

void FlywheelController::stop() {
}