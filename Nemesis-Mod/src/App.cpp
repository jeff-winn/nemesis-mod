#include "App.h"

App::App() {
    m_enabled = false;
}

void App::init() {
    m_flywheelController = new FlywheelController();
    m_flywheelController->init(9, 8, 7, 6);
    m_flywheelController->setDirection(MotorDirection::Forward);

    m_button1 = new Button();
    m_button1->init(12);
}

void App::run() {
    while (true) {
        if (m_button1->isPressed()) {
            startAll();
        }
        else {
            stopAll();
        }
    }
}

void App::startAll() {
    m_flywheelController->startAll();
}

void App::stopAll() {
    m_flywheelController->stopAll();
}