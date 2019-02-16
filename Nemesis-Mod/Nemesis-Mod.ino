#include <Arduino.h>
#include "src/LawgiverApp.h"

/* 
NOTE: This file intentionally serves as nothing more than an adapter to the Arduino tool chain requirements while allowing
all of the real functionality to move elsewhere allowing for easier maintenance.
*/

LawgiverApp* app;

void setup() {
    auto* hardware = new HardwareAccessLayer();

    auto* flywheelController = new FlywheelController(
        new DualG2HighPowerMotorShield18v18(
            0, 0, 9, 0, A0, 0, 0, 10, 0, A1),
        new Potentiometer(
            new AnalogPin(A3, hardware)),
        new Potentiometer(
            new AnalogPin(A4, hardware)));
    flywheelController->init();

    auto* revTrigger = new InterruptButton(
            new InterruptPin(3, EXTERNAL_INT_1, hardware));
    revTrigger->init(onRevTriggerStateChangedCallback);

    auto* firingTrigger = new InterruptButton(
            new InterruptPin(2, EXTERNAL_INT_0, hardware));
    firingTrigger->init(onFiringTriggerStateChangedCallback);

    app = new LawgiverApp(
        flywheelController,
        revTrigger,
        firingTrigger,
        hardware);
    app->init();
}

void loop() {
    app->run();    
}

void onRevTriggerStateChangedCallback() {
    app->onRevTriggerStateChangedCallback();
}

void onFiringTriggerStateChangedCallback() {
    app->onFiringTriggerStateChangedCallback();
}