#include <Arduino.h>
#include "src/App.h"

App* app;

// Defines the driver which controls the flywheel motors.
DualG2HighPowerMotorShield18v18 flywheelDriver(9, -1, 5, -1, A0, 10, -1, 6, -1, A1);

// Defines the driver which controls the belt feed motor.
G2HighPowerMotorShield18v17 beltDriver(17, -1, 11, -1, A2);

// Defines the driver for the onboard bluetooth module.
Adafruit_BluefruitLE_SPI bluetoothDriver(8, 7, 4);

// Defines the FRAM module for persistent data storage.
Adafruit_FRAM_I2C framModule;

ConfigurationSettings config(&framModule);
Mainboard mainboard;

void setup() {     
    app = new App(
        new FlywheelController(
            &mainboard, &flywheelDriver, &config),
        new FeedController(
            &mainboard, &beltDriver, &config),
        new PolledButton(
            new DigitalPin(13, &mainboard)),
        new PolledButton(
            new DigitalPin(12, &mainboard)),
        new BluetoothManager(
            &bluetoothDriver),
        new ConfigurationSettings(
            &framModule),
        &mainboard
    );

    app->init();
}

void loop() {
    app->run();
}