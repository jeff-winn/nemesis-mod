#include <Arduino.h>
#include <avr/sleep.h>
#include "src/Controllers/FlywheelController.h"
#include "src/Hardware/Button.h"

FlywheelController* m_flywheelController;
Button* m_revTrigger;

void setup() {
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();

    m_flywheelController = new FlywheelController(
        new DualG2HighPowerMotorShield18v18());

    m_flywheelController->init();

    m_revTrigger = new Button(new InterruptPin(3, INT1));
    m_revTrigger->init(onRevTriggerStateChanged);
}

void loop() {
    // Keep the device in a perpetual powered down state (interrupts will be used to awaken when needed).
    sleep_mode();
}

void onRevTriggerStateChanged() {
    if (m_revTrigger->isPressed()) {
        m_flywheelController->start();
    }
    else {
        m_flywheelController->stop();
    }
}