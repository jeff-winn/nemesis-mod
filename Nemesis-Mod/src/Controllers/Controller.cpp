#include "Controller.h"

void Controller::init() {    
}

void Controller::start() {
    if (m_isRunning) {
        return;
    }

    onStart();
    m_isRunning = true;
}

void Controller::stop() {
    if (!m_isRunning) {
        return;
    }

    onStop();
    m_isRunning = false;
}

bool Controller::isRunning() {
    return m_isRunning;
}