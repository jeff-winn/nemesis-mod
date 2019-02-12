#include <Arduino.h>
#include <avr/sleep.h>
#include "src/Controllers/FlywheelController.h"
#include "src/Hardware/InterruptButton.h"
#include "src/Hardware/PolledButton.h"

FlywheelController* m_flywheelController;
InterruptButton* m_revTrigger;
PolledButton* m_fireTrigger;

// Identifies whether the hardware should continue execution.
volatile bool CONTINUE_EXECUTION = false;

void setup() {
    set_sleep_mode(SLEEP_MODE_PWR_SAVE);

    m_flywheelController = new FlywheelController(
        new DualG2HighPowerMotorShield18v18(),
        new Potentiometer(new AnalogPin(A3)),
        new Potentiometer(new AnalogPin(A4)));
    m_flywheelController->init();

    m_revTrigger = new InterruptButton(
        new InterruptPin(3, INT1));
    m_revTrigger->init(m_revTriggerStateChangedCallback);

    m_fireTrigger = new PolledButton(
        new DigitalPin(0));
    m_fireTrigger->init();
}

void loop() {
    waitForWakeEvent();

    m_flywheelController->start();
    
    while (CONTINUE_EXECUTION) {
        if (m_fireTrigger->isPressed()) {
            // Start the feed motor assembly.
        }
        else {
            // Stop the feed motor assembly.
        }

        delay(10);
    }

    m_flywheelController->stop();
}

// Pauses the CPU until an external event wakes the device.
void waitForWakeEvent() {
    if (CONTINUE_EXECUTION) {
        return;
    }

    sleep_enable();
    sleep_mode();
}

// Attempts to wake the device.
void attemptToWakeTheDevice() {
    if (!CONTINUE_EXECUTION) {
        return;
    }

    sleep_disable();
}

void m_revTriggerStateChangedCallback() {
    CONTINUE_EXECUTION = m_revTrigger->isPressed();
    attemptToWakeTheDevice();
}