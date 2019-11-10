#include "../ConfigurationSettings.h"
#include "ConfigurationService.h"
#include "CustomUuid.h"
#include "RemoteCommandReceivedCallback.h"

ConfigurationService::ConfigurationService() : CustomBLEService(UUID128_SVC_CONFIGURATION) {
    _flywheelNormalSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_NORMAL_SPEED);
}

void onFlywheelNormalSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    onBluetoothRemoteCommandReceivedCallback(11, data, len, 1);
}

void ConfigurationService::init() {
    _flywheelNormalSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    _flywheelNormalSpeed.setPermission(SECMODE_OPEN, SECMODE_OPEN);
    _flywheelNormalSpeed.setFixedLen(4);
    _flywheelNormalSpeed.setWriteCallback(onFlywheelNormalSpeedWriteCallback);
    _flywheelNormalSpeed.begin();
    _flywheelNormalSpeed.write32(Settings.getFlywheelNormalSpeed());
}