#include <Arduino.h>
#include "src/App.h"

/* 
NOTE: This file intentionally serves as nothing more than an adapter to the Arduino tool chain requirements while allowing
all of the real functionality to move elsewhere allowing for easier maintenance.
*/

App* app;

void setup() {
    auto* hardware = new HardwareAccessLayer();
    
    auto* flywheelController = new FlywheelController(
        hardware,
        new DualG2HighPowerMotorShield18v18(
            0, 0, 5, 0, A0, 0, 0, 6, 0, A1),
        new Potentiometer(
            new AnalogPin(A3, hardware)),
        new Potentiometer(
            new AnalogPin(A4, hardware)));
    flywheelController->init();
    flywheelController->setSpeed(MotorSpeed::High);

    auto* feedController = new FeedController(
        hardware,
        new G2HighPowerMotorShield18v17(
            0, 0, 11, 0, A2));
    feedController->init();
    feedController->setSpeed(MotorSpeed::High);

    auto* revTrigger = new InterruptButton(
        new InterruptPin(13, hardware));
    revTrigger->init(onRevTriggerStateChangedCallback);

    auto* firingTrigger = new InterruptButton(
        new InterruptPin(12, hardware));
    firingTrigger->init(onFiringTriggerStateChangedCallback);

    app = new App(
        flywheelController,
        feedController,
        revTrigger,
        firingTrigger,
        hardware);
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