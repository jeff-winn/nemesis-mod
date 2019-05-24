#include <Arduino.h>
#include "src/App.h"

/* 
NOTE: This file intentionally serves as nothing more than an adapter to the Arduino tool chain requirements while allowing
all of the real functionality to move elsewhere allowing for easier maintenance.
*/

App* app;

void setup() {
    Serial.begin(115200);

    auto* mainboard = new Mainboard();
    
    auto* flywheelController = new FlywheelController(
        mainboard,
        new DualG2HighPowerMotorShield18v18(
            9, -1, 5, -1, A0, 10, -1, 6, -1, A1),
        NULL, 
        NULL);
    flywheelController->init();

    auto* feedController = new FeedController(
        mainboard,
        new G2HighPowerMotorShield18v17(
            17, -1, 11, -1, A2));
    feedController->init();

    auto* revTrigger = new InterruptButton(
        new InterruptPin(13, mainboard));
    revTrigger->init(onRevTriggerStateChangedCallback);

    auto* firingTrigger = new InterruptButton(
        new InterruptPin(12, mainboard));
    firingTrigger->init(onFiringTriggerStateChangedCallback);

    // See documentation for Bluefruit pinouts (these are not exposed on the MCU but are identifed within the documentation).
    auto* bluetoothController = new BluetoothController(
        new Adafruit_BluefruitLE_SPI(8, 7, 4));
        
    bluetoothController->init(true, NULL, NULL);

    app = new App(
        flywheelController,
        feedController,
        revTrigger,
        firingTrigger,
        bluetoothController,
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