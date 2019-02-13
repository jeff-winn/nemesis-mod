#include <Arduino.h>
#include "src/LawgiverApp.h"

/* 
NOTE: This file intentionally serves as nothing more than an adapter to the Arduino tool chain requirements while allowing
all of the real functionality to move elsewhere allowing for easier maintenance.
*/

LawgiverApp* app;

void setup() {
    auto* hal = new HAL();

    auto* flywheelController = new FlywheelController(
        new DualG2HighPowerMotorShield18v18(
            0, 0, 9, 0, A0, 0, 0, 10, 0, A1),
        new Potentiometer(
            new AnalogPin(A3, hal)),
        new Potentiometer(
            new AnalogPin(A4, hal)));
    flywheelController->init();

    auto* revTrigger = new InterruptButton(
            new InterruptPin(3, INT1, hal));
    revTrigger->init(onRevTriggerStateChangedCallback);

    auto* firingTrigger = new InterruptButton(
            new InterruptPin(2, INT0, hal));
    firingTrigger->init(onFiringTriggerStateChangedCallback);

    app = new LawgiverApp(
        flywheelController,
        revTrigger,
        firingTrigger,
        hal);
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