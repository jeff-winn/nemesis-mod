#include <Arduino.h>
#include <avr/sleep.h>
#include "src/Controllers/FlywheelController.h"
#include "src/Hardware/Button.h"

FlywheelController* m_flywheelController;
Button* m_revTrigger;

// Identifies whether the hardware should continue execution.
volatile bool CONTINUE_EXECUTION = false;

void setup() {
    set_sleep_mode(SLEEP_MODE_PWR_SAVE);

    m_flywheelController = new FlywheelController(
        new DualG2HighPowerMotorShield18v18(),
        new Potentiometer(new AnalogPin(A3)),
        new Potentiometer(new AnalogPin(A4)));

    m_flywheelController->init();

    m_revTrigger = new Button(new InterruptPin(3, INT1));
    m_revTrigger->init(onRevTriggerStateChanged);
}

void loop() {
    waitForWakeEvent();

    m_flywheelController->start();
    
    while (CONTINUE_EXECUTION) {
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

void attemptToWakeTheDevice() {
    if (!CONTINUE_EXECUTION) {
        return;
    }

    sleep_disable();
}

void onRevTriggerStateChanged() {
    CONTINUE_EXECUTION = m_revTrigger->isPressed();
    attemptToWakeTheDevice();
}