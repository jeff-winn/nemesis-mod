#include <Arduino.h>
#include "src/App.h"

/* 
NOTE: This file intentionally serves as nothing more than an adapter to the Arduino tool chain requirements while allowing
all of the real functionality to move elsewhere allowing for easier maintenance.
*/

App* app;

void setup() {
    auto* mainboard = new Mainboard();
    
    auto* flywheelController = new FlywheelController(
        mainboard,
        new DualG2HighPowerMotorShield18v18(
            9, 0, 5, 0, A0, 10, 0, 6, 0, A1),
        NULL, 
        NULL);
    flywheelController->init();

    auto* feedController = new FeedController(
        mainboard,
        new G2HighPowerMotorShield18v17(
            17, 0, 11, 0, A2));
    feedController->init();

    auto* revTrigger = new InterruptButton(
        new InterruptPin(13, mainboard));
    revTrigger->init(onRevTriggerStateChangedCallback);

    auto* firingTrigger = new InterruptButton(
        new InterruptPin(12, mainboard));
    firingTrigger->init(onFiringTriggerStateChangedCallback);

    app = new App(
        flywheelController,
        feedController,
        revTrigger,
        firingTrigger,
        mainboard);

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