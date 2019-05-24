#include <Arduino.h>
#include "src/App.h"

/* 
NOTE: This file intentionally serves as nothing more than an adapter to the Arduino tool chain requirements while allowing
all of the real functionality to move elsewhere allowing for easier maintenance.
*/

App* app;
Mainboard mainboard;

void setup() {
    Serial.begin(115200);
    
    auto* irqPin = new InterruptPin(13, &mainboard);
    irqPin->init(onRevTriggerStateChangedCallback, InterruptMode::All);

    app = new App(
        new FlywheelController(
            &mainboard,
            new DualG2HighPowerMotorShield18v18(
                9, -1, 5, -1, A0, 10, -1, 6, -1, A1),
            NULL, 
            NULL),
        new FeedController(
            &mainboard,
            new G2HighPowerMotorShield18v17(
                17, -1, 11, -1, A2)),
        new InterruptButton(irqPin),
        new PolledButton(
            new DigitalPin(12, &mainboard)),
        new BluetoothController(
            new Adafruit_BluefruitLE_SPI(
                8, 7, 4)),
        &mainboard);

    app->init();
}

void loop() {
    app->run();
}

void onRevTriggerStateChangedCallback() {
    app->onRevTriggerStateChangedCallback();
}