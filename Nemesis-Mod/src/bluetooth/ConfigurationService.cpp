#include "../ConfigurationSettings.h"
#include "ConfigurationService.h"
#include "CustomUuid.h"
#include "RemoteCommandReceivedCallback.h"

ConfigurationService::ConfigurationService() : CustomBLEService(UUID128_SVC_CONFIGURATION) {
    _flywheelNormalSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_NORMAL_SPEED);
    _flywheelTrimVariance = BLECharacteristic(UUID128_CHR_FLYWHEEL_TRIM_VARIANCE);
}

void onFlywheelNormalSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    onBluetoothRemoteCommandReceivedCallback(11, data, len, 1);
}

void onFlywheelTrimVarianceWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    onBluetoothRemoteCommandReceivedCallback(11, data, len, 7);
}

void ConfigurationService::init() {
    _flywheelNormalSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    _flywheelNormalSpeed.setPermission(SECMODE_OPEN, SECMODE_OPEN);
    _flywheelNormalSpeed.setFixedLen(4);
    _flywheelNormalSpeed.setUserDescriptor("Flywheel Normal Speed");
    _flywheelNormalSpeed.setWriteCallback(onFlywheelNormalSpeedWriteCallback);
    _flywheelNormalSpeed.begin();
    _flywheelNormalSpeed.write32(Settings.getFlywheelNormalSpeed());

    _flywheelTrimVariance.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    _flywheelTrimVariance.setPermission(SECMODE_OPEN, SECMODE_OPEN);
    _flywheelTrimVariance.setFixedLen(4);
    _flywheelTrimVariance.setWriteCallback(onFlywheelTrimVarianceWriteCallback);
    _flywheelTrimVariance.begin();

    auto value = Settings.getFlywheelTrimVariance();
    _flywheelTrimVariance.write(&value, 4);
}