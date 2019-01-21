#include "App.h"

App::App() {
    m_enabled = false;
}

void App::init() {
    m_m1 = new Motor();
    m_m1->init(4, 9);

    m_m2 = new Motor();
    m_m2->init(2, 5);
}

void App::run() {
    if (m_enabled) {
        m_m1->start();
        m_m2->start();
    }
    else {
        m_m1->stop();
        m_m2->stop();
    }
}