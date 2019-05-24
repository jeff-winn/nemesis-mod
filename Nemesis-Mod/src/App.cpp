#include "App.h"

// Indicates whether the blaster should continue execution.
volatile bool SHOULD_CONTINUE_EXECUTION = false;

// Indicates whether the operator has authenticated prior to releasing the software lock.
volatile bool HAS_OPERATOR_AUTHENTICATED = true;

App::App(FlywheelController* flywheelController, FeedController* feedController, InterruptButton* revTrigger, PolledButton* firingTrigger, BluetoothController* bluetoothController, Mainboard* hardware) {
    m_flywheelController = flywheelController;
    m_feedController = feedController;
    m_revTrigger = revTrigger;
    m_firingTrigger = firingTrigger;
    m_bluetoothController = bluetoothController;
    m_hardware = hardware;    
}

void App::onRevTriggerStateChangedCallback() {
    SHOULD_CONTINUE_EXECUTION = m_revTrigger->isPressed();
}

void App::run() {
    waitForWakeEvent();
    if (!HAS_OPERATOR_AUTHENTICATED || !SHOULD_CONTINUE_EXECUTION) {
        return;
    }

    m_flywheelController->start();
    
    while (SHOULD_CONTINUE_EXECUTION) {
        if (m_firingTrigger->isPressed()) {
            m_feedController->start();
        }
        else {
            m_feedController->stop();
        }

        m_hardware->delaySafe(10);
    }

    m_feedController->stop();
    m_flywheelController->stop();
}

void App::waitForWakeEvent() {
    if (SHOULD_CONTINUE_EXECUTION) {
        return;
    }

#if defined (__RELEASE__)
    m_hardware->sleepSafe();
#endif
}

void App::init() {
    m_flywheelController->init();
    m_feedController->init();
    m_bluetoothController->init();
    
    m_flywheelController->setSpeed(FlywheelSpeed::Normal);
    m_feedController->setSpeed(BeltSpeed::Normal);
}