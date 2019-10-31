#include <Arduino.h>
#include "src/App.h"

// Defines the driver which controls the flywheel motors.
DualG2HighPowerMotorShield18v18 flywheelDriver = DualG2HighPowerMotorShield18v18(9, -1, 5, -1, A0, 10, -1, 6, -1, A1);

// Defines the driver which controls the belt feed motor.
G2HighPowerMotorShield18v17 beltDriver = G2HighPowerMotorShield18v17(17, -1, 11, -1, A2);

// Defines the FRAM module for persistent data storage.
Adafruit_FRAM_I2C fram;

ConfigurationSettings config = ConfigurationSettings(&fram);
Mainboard mainboard;

App* app;

void setup() {
    app = new App(
        new FlywheelController(
            &mainboard, &flywheelDriver, &config),
        new FeedController(
            &mainboard, &beltDriver, &config),
        new Button(
            new DigitalPin(13, &mainboard)),
        new Button(
            new DigitalPin(12, &mainboard)),
        new Button(
            new DigitalPin(18, &mainboard), true),
        new BluetoothManager(),
        &config,
        &mainboard
    );

    app->init();
}

void loop() {
    app->run();
}