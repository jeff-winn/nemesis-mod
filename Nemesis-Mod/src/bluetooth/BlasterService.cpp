#include "../ConfigurationSettings.h"
#include "BlasterService.h"
#include "CustomUuid.h"
#include "RemoteCommandReceivedCallback.h"

BlasterService::BlasterService() : CustomBLEService(UUID128_SVC_NERF_BLASTER) {
    _flywheelSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_SPEED);
    _flywheelM1TrimSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_M1TRIM_SPEED);
    _flywheelM2TrimSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_M2TRIM_SPEED);
    _beltSpeed = BLECharacteristic(UUID128_CHR_BELT_SPEED);
}

void onFlywheelSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    onBluetoothRemoteCommandReceivedCallback(200, data, len, 0);
}

void onFlywheelM1TrimAdjustmentWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    onBluetoothRemoteCommandReceivedCallback(201, data, len, 1);
}

void onFlywheelM2TrimAdjustmentWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    onBluetoothRemoteCommandReceivedCallback(201, data, len, 2); 
}

void onBeltSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    onBluetoothRemoteCommandReceivedCallback(100, data, len, 0);
}

void BlasterService::init() {  
    _flywheelSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    _flywheelSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    _flywheelSpeed.setFixedLen(1);
    _flywheelSpeed.setUserDescriptor("Flywheel Speed");
    _flywheelSpeed.setWriteCallback(onFlywheelSpeedWriteCallback);
    _flywheelSpeed.begin();
    _flywheelSpeed.write8(0x00);

    _flywheelM1TrimSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    _flywheelM1TrimSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    _flywheelM1TrimSpeed.setFixedLen(4);
    _flywheelM1TrimSpeed.setUserDescriptor("Flywheel M1 Trim Speed");
    _flywheelM1TrimSpeed.setWriteCallback(onFlywheelM1TrimAdjustmentWriteCallback);
    _flywheelM1TrimSpeed.begin();

    auto m1TrimSpeed = Settings.getFlywheelM1TrimAdjustment();
    _flywheelM1TrimSpeed.write(&m1TrimSpeed, 4);

    _flywheelM2TrimSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    _flywheelM2TrimSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    _flywheelM2TrimSpeed.setFixedLen(4);
    _flywheelM2TrimSpeed.setUserDescriptor("Flywheel M2 Trim Speed");
    _flywheelM2TrimSpeed.setWriteCallback(onFlywheelM2TrimAdjustmentWriteCallback);
    _flywheelM2TrimSpeed.begin();

    auto m2TrimSpeed = Settings.getFlywheelM2TrimAdjustment();
    _flywheelM2TrimSpeed.write(&m2TrimSpeed, 4);

    _beltSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    _beltSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    _beltSpeed.setFixedLen(1);
    _beltSpeed.setUserDescriptor("Belt Speed");
    _beltSpeed.setWriteCallback(onBeltSpeedWriteCallback);
    _beltSpeed.begin();
    _beltSpeed.write8(0x00);
}