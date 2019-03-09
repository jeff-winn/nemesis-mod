#include "App.h"

// Indicates whether the blaster should continue execution.
volatile bool SHOULD_CONTINUE_EXECUTION = false;

// Indicates whether the operator has authenticated prior to releasing the software lock.
volatile bool HAS_OPERATOR_AUTHENTICATED = true;

// Indicates whether the blaster should fire rounds at the target.
volatile bool SHOULD_FIRE_ROUNDS = false;

App::App(FlywheelController* flywheelController, FeedController* feedController, InterruptButton* revTrigger, InterruptButton* firingTrigger, HardwareAccessLayer* p_hardware) {
    m_flywheelController = flywheelController;
    m_feedController = feedController;
    m_revTrigger = revTrigger;
    m_firingTrigger = firingTrigger;
    hardware = p_hardware;    
}

void App::onFiringTriggerStateChangedCallback() {
    SHOULD_FIRE_ROUNDS = m_firingTrigger->isPressed();    
}

void App::onRevTriggerStateChangedCallback() {
    SHOULD_CONTINUE_EXECUTION = m_revTrigger->isPressed();
}

void App::run() {
    waitForWakeEvent();
    if (!HAS_OPERATOR_AUTHENTICATED) {
        return;
    }

    m_flywheelController->setSpeed(FlywheelSpeed::Low);
    m_flywheelController->start();
    
    while (SHOULD_CONTINUE_EXECUTION) {
        if (SHOULD_FIRE_ROUNDS) {
            m_feedController->start();
        }
        else {
            m_feedController->stop();
        }

        delay(10);
    }

    m_flywheelController->stop();
}

void App::waitForWakeEvent() {
    if (SHOULD_CONTINUE_EXECUTION) {
        return;
    }

    hardware->sleep();
}