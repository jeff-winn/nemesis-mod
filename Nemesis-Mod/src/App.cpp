#include "App.h"

// Indicates whether the hardware should continue execution.
volatile bool SHOULD_CONTINUE_EXECUTION = false;

// Indicates whether the operator has authenticated prior to releasing the software lock.
volatile bool HAS_OPERATOR_AUTHENTICATED = true;

// Indicates whether the blaster should fire rounds at the target.
volatile bool SHOULD_FIRE_ROUNDS = false;

App::App(FlywheelController* flywheelController, PolledButton* revTrigger, PolledButton* firingTrigger, HardwareAccessLayer* p_hardware) {
    m_flywheelController = flywheelController;
    m_revTrigger = revTrigger;
    m_firingTrigger = firingTrigger;
    hardware = p_hardware;    
}

void App::init() {
    hardware->enableSleepMode();
}

void App::onFiringTriggerStateChangedCallback() {
    SHOULD_FIRE_ROUNDS = m_firingTrigger->isPressed();    
}

void App::onRevTriggerStateChangedCallback() {
    SHOULD_CONTINUE_EXECUTION = m_revTrigger->isPressed();
    attemptToWakeTheDevice();
}

void App::run() {
    if (m_revTrigger->isPressed()) {
        m_flywheelController->setSpeed(FlywheelSpeed::Low);
        m_flywheelController->start();        
    }
    else {
        m_flywheelController->stop();
    }

    // waitForWakeEvent();
    // if (!HAS_OPERATOR_AUTHENTICATED) {
    //     return;
    // }

    // m_flywheelController->setSpeed(FlywheelSpeed::Low);
    // m_flywheelController->start();
    
    // while (SHOULD_CONTINUE_EXECUTION) {
    //     if (SHOULD_FIRE_ROUNDS) {
    //         // Start firing rounds.
    //     }
    //     else {
    //         // Stop firing rounds.
    //     }

    //     delay(10);
    // }

    // m_flywheelController->stop();
}

void App::waitForWakeEvent() {
    if (SHOULD_CONTINUE_EXECUTION) {
        return;
    }

    hardware->sleep();
}

void App::attemptToWakeTheDevice() {
    if (!SHOULD_CONTINUE_EXECUTION) {
        return;
    }

    hardware->wake();
}