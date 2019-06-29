#include <Arduino.h>
#include "src/App.h"

// Defines the driver which controls the flywheel motors.
DualG2HighPowerMotorShield18v18 flywheelDriver(9, -1, 5, -1, A0, 10, -1, 6, -1, A1);

// Defines the driver which controls the belt feed motor.
G2HighPowerMotorShield18v17 beltDriver(17, -1, 11, -1, A2);

// Defines the driver for the onboard bluetooth module.
Adafruit_BluefruitLE_SPI bluetoothDriver(8, 7, 4);

// Defines the FRAM module for persistent data storage.
Adafruit_FRAM_I2C fram;

ConfigurationSettings config(&fram);
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
        new BluetoothManager(
            &bluetoothDriver),
        &config,
        &mainboard
    );

    app->init();
}

void loop() {
    app->run();
}