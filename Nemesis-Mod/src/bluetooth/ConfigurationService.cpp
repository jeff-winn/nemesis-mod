#include "../Callbacks.h"
#include "../ConfigurationSettings.h"
#include "ConfigurationService.h"
#include "CustomUuid.h"

uint8_t CONFIGURATION_COMMAND_ID = 10;

ConfigurationService::ConfigurationService() : CustomBLEService(UUID128_SVC_CONFIGURATION) {
    m_flywheelNormalSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_NORMAL_SPEED);
    m_flywheelTrimVariance = BLECharacteristic(UUID128_CHR_FLYWHEEL_TRIM_VARIANCE);
    m_beltMaxSpeed = BLECharacteristic(UUID128_CHR_BELT_MAX_SPEED);
}

void onFlywheelNormalSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(CONFIGURATION_COMMAND_ID, data, len, 1);
}

void onFlywheelTrimVarianceWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(CONFIGURATION_COMMAND_ID, data, len, 7);
}

void onBeltMaxSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(CONFIGURATION_COMMAND_ID, data, len, 6);
}

void ConfigurationService::init() {
    m_flywheelNormalSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_flywheelNormalSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_flywheelNormalSpeed.setFixedLen(4);
    m_flywheelNormalSpeed.setUserDescriptor("Flywheel Normal Speed");
    m_flywheelNormalSpeed.setWriteCallback(onFlywheelNormalSpeedWriteCallback);
    m_flywheelNormalSpeed.begin();
    m_flywheelNormalSpeed.write32(Settings.getFlywheelNormalSpeed());

    m_flywheelTrimVariance.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_flywheelTrimVariance.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_flywheelTrimVariance.setFixedLen(4);
    m_flywheelTrimVariance.setUserDescriptor("Flywheel Trim Variance");
    m_flywheelTrimVariance.setWriteCallback(onFlywheelTrimVarianceWriteCallback);
    m_flywheelTrimVariance.begin();

    auto flywheelTrimVariance = Settings.getFlywheelTrimVariance();
    m_flywheelTrimVariance.write(&flywheelTrimVariance, 4);

    m_beltMaxSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_beltMaxSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_beltMaxSpeed.setFixedLen(4);
    m_beltMaxSpeed.setUserDescriptor("Belt Feed Max Speed");
    m_beltMaxSpeed.setWriteCallback(onBeltMaxSpeedWriteCallback);
    m_beltMaxSpeed.begin();

    auto feedMaxSpeed = Settings.getFeedMaxSpeed();
    m_beltMaxSpeed.write(&feedMaxSpeed, 4);
}