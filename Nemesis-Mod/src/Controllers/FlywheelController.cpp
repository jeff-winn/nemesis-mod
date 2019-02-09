#include "FlywheelController.h"

FlywheelController::FlywheelController(DualG2HighPowerMotorShield18v18* motorController, Potentiometer* pot1, Potentiometer* pot2) {
    m_motorController = motorController;
    m_pot1 = pot1;
    m_pot2 = pot2;
}

void FlywheelController::init() {
    m_motorController->init();
    m_motorController->calibrateCurrentOffsets();
    
    m_motorController->flipM1(true);
    delay(1);

    m_motorController->flipM2(true);
    delay(1);    
}

void FlywheelController::start() {
    m_motorController->enableDrivers();
    delay(1);
    
    m_motorController->setSpeeds(400, 400);
    delay(1);
}

void FlywheelController::stop() {
    m_motorController->setSpeeds(0, 0);

    delay(1);
    m_motorController->disableDrivers();
}