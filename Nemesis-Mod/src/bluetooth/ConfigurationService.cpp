#include "../Callbacks.h"
#include "../ConfigurationSettings.h"
#include "ConfigurationService.h"
#include "CustomUuid.h"

uint8_t CONFIGURATION_COMMAND_ID = 10;

ConfigurationService::ConfigurationService() : CustomBLEService(UUID128_SVC_CONFIGURATION) {
    _flywheelNormalSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_NORMAL_SPEED);
    _flywheelTrimVariance = BLECharacteristic(UUID128_CHR_FLYWHEEL_TRIM_VARIANCE);
}

void onFlywheelNormalSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(CONFIGURATION_COMMAND_ID, data, len, 1);
}

void onFlywheelTrimVarianceWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(CONFIGURATION_COMMAND_ID, data, len, 7);
}

void ConfigurationService::init() {
    _flywheelNormalSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    _flywheelNormalSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    _flywheelNormalSpeed.setFixedLen(4);
    _flywheelNormalSpeed.setUserDescriptor("Flywheel Normal Speed");
    _flywheelNormalSpeed.setWriteCallback(onFlywheelNormalSpeedWriteCallback);
    _flywheelNormalSpeed.begin();
    _flywheelNormalSpeed.write32(Settings.getFlywheelNormalSpeed());

    _flywheelTrimVariance.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    _flywheelTrimVariance.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    _flywheelTrimVariance.setFixedLen(4);
    _flywheelTrimVariance.setWriteCallback(onFlywheelTrimVarianceWriteCallback);
    _flywheelTrimVariance.begin();

    auto value = Settings.getFlywheelTrimVariance();
    _flywheelTrimVariance.write(&value, 4);
}