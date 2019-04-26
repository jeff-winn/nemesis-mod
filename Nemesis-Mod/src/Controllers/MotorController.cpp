#include "MotorController.h"

void MotorController::init() {    
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

void MotorController::setSpeed(MotorSpeed speed) {
    m_speed = speed;
}

MotorSpeed MotorController::getSpeed() {
    return m_speed;
}