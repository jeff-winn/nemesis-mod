#include <Arduino.h>
#include "App.h"

App::App() {
    m_enabled = false;
}

void App::init() {
    m_flywheelController = new FlywheelController();
    m_flywheelController->init(FlywheelMotor::Motor1, 9, A0);  // (OC1A) to L298->IN2
    m_flywheelController->init(FlywheelMotor::Motor2, 10, A1); // (OC1B) to L298->IN4

    m_revTrigger = new Button();
    m_revTrigger->init(12);
}

void App::run() {
    while (true) {
        if (m_revTrigger->isPressed()) {
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