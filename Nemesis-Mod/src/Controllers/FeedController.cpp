#include "FeedController.h"
#include <Arduino.h>

FeedController::FeedController(AnalogPin* pin) {
    m_pin = pin;
}

void FeedController::init() {
    m_pin->setOutputMode();
}

void FeedController::start() {
    if (m_isRunning) {
        return;
    }

    m_pin->write(255);
    m_isRunning = true;
}

void FeedController::stop() {
    if (!m_isRunning) {
        return;
    }

    m_pin->write(0);
    m_isRunning = false;
}