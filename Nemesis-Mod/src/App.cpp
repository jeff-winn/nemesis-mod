#include "App.h"

App::App() {
    m_enabled = false;
}

void App::init() {
    m_motor1 = new Motor();
    m_motor1->init(4, 9);

    m_motor2 = new Motor();
    m_motor2->init(2, 5);

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
    m_motor1->start();
    m_motor2->start();
}

void App::stopAll() {
    m_motor1->stop();
    m_motor2->stop();
}