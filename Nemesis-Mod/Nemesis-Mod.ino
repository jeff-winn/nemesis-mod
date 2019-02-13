#include <Arduino.h>
#include <avr/sleep.h>
#include "src/Controllers/FlywheelController.h"
#include "src/Hardware/InterruptButton.h"
#include "src/Hardware/PolledButton.h"

HAL* HardwareAccessLayer;
FlywheelController* flywheelController;
InterruptButton* revTrigger;

// Identifies whether the hardware should continue execution.
volatile bool SHOULD_CONTINUE_EXECUTION = false;

// Identifies whether the operator has authenticated prior to releasing the software lock.
volatile bool HAS_OPERATOR_AUTHENTICATED = true;

void setup() {
    set_sleep_mode(SLEEP_MODE_PWR_SAVE);

    HardwareAccessLayer = new HAL();

    flywheelController = new FlywheelController(
        new DualG2HighPowerMotorShield18v18(
            0, 0, 9, 0, A0, 0, 0, 10, 0, A1),
        new Potentiometer(
            new AnalogPin(A3, HardwareAccessLayer)),
        new Potentiometer(
            new AnalogPin(A4, HardwareAccessLayer)));
    flywheelController->init();

    revTrigger = new InterruptButton(
        new InterruptPin(3, INT1, HardwareAccessLayer));
    revTrigger->init(revTriggerStateChangedCallback);
}

void loop() {
    waitForWakeEvent();
    if (!HAS_OPERATOR_AUTHENTICATED) {
        return;
    }

    flywheelController->setSpeed(FlywheelSpeed::Low);
    flywheelController->start();
    
    while (SHOULD_CONTINUE_EXECUTION) {
        delay(10);
    }

    flywheelController->stop();
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

void revTriggerStateChangedCallback() {
    SHOULD_CONTINUE_EXECUTION = revTrigger->isPressed();
    attemptToWakeTheDevice();
}