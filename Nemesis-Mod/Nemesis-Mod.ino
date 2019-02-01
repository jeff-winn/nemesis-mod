#include <Arduino.h>
#include <avr/sleep.h>
#include "src/Controllers/FlywheelController.h"
#include "src/Hardware/Button.h"

using namespace App::Controllers;

FlywheelController* m_flywheelController;
Button* m_revTrigger;

void setup() {
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();

    m_flywheelController = new FlywheelController();
    m_flywheelController->init(FlywheelMotor::Motor1, 9, A0);  // (OC1A) to L298->IN2
    m_flywheelController->init(FlywheelMotor::Motor2, 10, A1); // (OC1B) to L298->IN4

    m_revTrigger = new Button();
    m_revTrigger->init(2, INT0, onRevTriggerStateChanged);
}

void loop() {
    // Keep the device in a perpetual powered down state (interrupts will be used to awaken when needed).
    sleep_mode();
}

void onRevTriggerStateChanged() {
    if (m_revTrigger->isPressed()) {
        m_flywheelController->startAll();
    }
    else {
        m_flywheelController->stopAll();
    }
}