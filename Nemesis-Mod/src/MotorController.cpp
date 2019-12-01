#include "MotorController.h"

void MotorController::init(ConfigurationSettings* settings) {    
}

void MotorController::start() {
    if (m_isRunning) {
        return;
    }

    onStart();
    m_isRunning = true;
}

void MotorController::stop() {
    if (!m_isRunning) {
        return;
    }

    onStop();
    m_isRunning = false;
}

bool MotorController::isRunning() {
    return m_isRunning;
}