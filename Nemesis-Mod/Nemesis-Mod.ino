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
        new DualG2HighPowerMotorShield18v18(
            0, 0, 5, 0, A0, 0, 0, 10, 0, A1),
        new Potentiometer(
            new AnalogPin(A3, hardware)),
        new Potentiometer(
            new AnalogPin(A4, hardware)));
    flywheelController->init();

    auto* revTrigger = new PolledButton(
        new DigitalPin(11, hardware));

    auto* firingTrigger = new PolledButton(
        new DigitalPin(12, hardware));

    app = new App(
        flywheelController,
        revTrigger,
        firingTrigger,
        hardware);
    app->init();
}

void loop() {
    app->run();    
}