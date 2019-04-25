#include "FeedController.h"

FeedController::FeedController(HardwareAccessLayer* hardware, G2HighPowerMotorShield18v17* motorController) {
    m_hardware = hardware;
    m_motorController = motorController;
}

void FeedController::init() {
    m_motorController->init();
    m_motorController->calibrateCurrentOffset();

    m_hardware->delaySafe(1);    
}

void FeedController::onStart() {
    m_motorController->setSpeed(400);
    m_hardware->delaySafe(1);
}

void FeedController::onStop() {
    m_motorController->setSpeed(0);
    m_hardware->delaySafe(1);
}