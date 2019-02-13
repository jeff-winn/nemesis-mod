#include <Arduino.h>
#include <avr/sleep.h>
#include "src/Controllers/FlywheelController.h"
#include "src/Hardware/InterruptButton.h"
#include "src/Hardware/PolledButton.h"

FlywheelController* m_flywheelController;
InterruptButton* m_revTrigger;

// Identifies whether the hardware should continue execution.
volatile bool SHOULD_CONTINUE_EXECUTION = false;

// Identifies whether the operator has authenticated prior to releasing the software lock.
volatile bool HAS_OPERATOR_AUTHENTICATED = true;

void setup() {
    set_sleep_mode(SLEEP_MODE_PWR_SAVE);

    m_flywheelController = new FlywheelController(
        new DualG2HighPowerMotorShield18v18(0, 0, 9, 0, A0, 0, 0, 10, 0, A1),
        new Potentiometer(new AnalogPin(A3)),
        new Potentiometer(new AnalogPin(A4)));
    m_flywheelController->init();

    m_revTrigger = new InterruptButton(
        new InterruptPin(3, INT1));
    m_revTrigger->init(m_revTriggerStateChangedCallback);
}

void loop() {
    waitForWakeEvent();
    if (!HAS_OPERATOR_AUTHENTICATED) {
        return;
    }

    m_flywheelController->setSpeed(FlywheelSpeed::Low);
    m_flywheelController->start();
    
    while (SHOULD_CONTINUE_EXECUTION) {
        delay(10);
    }

    m_flywheelController->stop();
}

// Pauses the CPU until an external event wakes the device.
void waitForWakeEvent() {
    if (SHOULD_CONTINUE_EXECUTION) {
        return;
    }

    sleep_enable();
    sleep_mode();
}

// Attempts to wake the device.
void attemptToWakeTheDevice() {
    if (!SHOULD_CONTINUE_EXECUTION) {
        return;
    }

    sleep_disable();
}

void m_revTriggerStateChangedCallback() {
    SHOULD_CONTINUE_EXECUTION = m_revTrigger->isPressed();
    attemptToWakeTheDevice();
}