#include "BlasterSpeedService.h"
#include "CustomUuid.h"
#include "RemoteCommandReceivedCallback.h"

BlasterSpeedService::BlasterSpeedService() : CustomBLEService(UUID128_SVC_NERF_BLASTER) {
    _flywheelSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_SPEED);
    _beltSpeed = BLECharacteristic(UUID128_CHR_BELT_SPEED);
}

void BlasterSpeedService::init() {   
    _flywheelSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    _flywheelSpeed.setPermission(SECMODE_OPEN, SECMODE_OPEN);
    _flywheelSpeed.setFixedLen(1);
    _flywheelSpeed.setWriteCallback(onFlywheelSpeedWriteCallback);
    _flywheelSpeed.begin();
    _flywheelSpeed.write8(0x00);

    _beltSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    _beltSpeed.setPermission(SECMODE_OPEN, SECMODE_OPEN);
    _beltSpeed.setFixedLen(1);
    _beltSpeed.setWriteCallback(onBeltSpeedWriteCallback);
    _beltSpeed.begin();
    _beltSpeed.write8(0x00);
}

void onFlywheelSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
  onBluetoothRemoteCommandReceivedCallback(200, data, len);
}

void onBeltSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
  onBluetoothRemoteCommandReceivedCallback(100, data, len);
}