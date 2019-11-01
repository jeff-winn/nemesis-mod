#include <Arduino.h>
#include "src/App.h"
#include "src/BluetoothManager.h"

// Defines the driver which controls the flywheel motors.
DualG2HighPowerMotorShield18v18 flywheelDriver = DualG2HighPowerMotorShield18v18(31, -1, 27, -1, A0, 11, -1, 30, -1, A1);

// Defines the driver which controls the belt feed motor.
G2HighPowerMotorShield18v17 beltDriver = G2HighPowerMotorShield18v17(17, -1, 7, -1, A2);

// Defines the FRAM module for persistent data storage.
Adafruit_FRAM_I2C fram;

ConfigurationSettings config = ConfigurationSettings(&fram);
Mainboard mainboard;

BluetoothManager* ble;
App* app;

void setup() {
    ble = new BluetoothManager();
    ble->beginInit(OnFlywheelSpeedChangedCallback, OnBeltSpeedChangedCallback);

    app = new App(
        new FlywheelController(
            &mainboard, &flywheelDriver, &config),
        new FeedController(
            &mainboard, &beltDriver, &config),
        new Button(
            new DigitalPin(16, &mainboard)),
        new Button(
            new DigitalPin(15, &mainboard)),
        new Button(
            new DigitalPin(28, &mainboard), true),
        &config,
        &mainboard
    );

    app->init();
}

void loop() {
    app->run();
}

void OnFlywheelSpeedChangedCallback(uint16_t handle, BLECharacteristic* chr, uint8_t* data, uint16_t length) {
    int newSpeed = (int)data;
    flywheelDriver.setSpeeds(newSpeed, newSpeed);
}

void OnBeltSpeedChangedCallback(uint16_t handle, BLECharacteristic* chr, uint8_t* data, uint16_t length) {
    beltDriver.setSpeed((int)data);
}