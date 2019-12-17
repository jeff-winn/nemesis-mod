#include "../Callbacks.h"
#include "../ConfigurationSettings.h"
#include "ConfigurationService.h"
#include "CustomUuid.h"

uint8_t CONFIGURATION_COMMAND_ID = 10;

ConfigurationService::ConfigurationService() : CustomBLEService(UUID128_SVC_CONFIGURATION) {
    m_flywheelNormalSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_NORMAL_SPEED);
    m_flywheelKidSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_KID_SPEED);
    m_flywheelLudicrousSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_LUDICROUS_SPEED);
    m_flywheelTrimVariance = BLECharacteristic(UUID128_CHR_FLYWHEEL_TRIM_VARIANCE);
    m_beltNormalSpeed = BLECharacteristic(UUID128_CHR_BELT_NORMAL_SPEED);
    m_beltMediumSpeed = BLECharacteristic(UUID128_CHR_BELT_MEDIUM_SPEED);
    m_beltMaxSpeed = BLECharacteristic(UUID128_CHR_BELT_MAX_SPEED);
}

void onFlywheelKidSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(CONFIGURATION_COMMAND_ID, data, len, 1);
}

void onFlywheelNormalSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(CONFIGURATION_COMMAND_ID, data, len, 2);
}

void onFlywheelLudicrousSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(CONFIGURATION_COMMAND_ID, data, len, 3);
}

void onBeltNormalSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(CONFIGURATION_COMMAND_ID, data, len, 4);
}

void onBeltMediumSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(CONFIGURATION_COMMAND_ID, data, len, 5);
}

void onBeltMaxSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(CONFIGURATION_COMMAND_ID, data, len, 6);
}

void onFlywheelTrimVarianceWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(CONFIGURATION_COMMAND_ID, data, len, 7);
}

void ConfigurationService::init() {
    m_flywheelNormalSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_flywheelNormalSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_flywheelNormalSpeed.setFixedLen(4);
    m_flywheelNormalSpeed.setUserDescriptor("Flywheel Normal Speed");
    m_flywheelNormalSpeed.setWriteCallback(onFlywheelNormalSpeedWriteCallback);
    m_flywheelNormalSpeed.begin();
    m_flywheelNormalSpeed.write32(Settings.getFlywheelNormalSpeed());

    m_flywheelKidSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_flywheelKidSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_flywheelKidSpeed.setFixedLen(4);
    m_flywheelKidSpeed.setUserDescriptor("Flywheel Kid Speed");
    m_flywheelKidSpeed.setWriteCallback(onFlywheelKidSpeedWriteCallback);
    m_flywheelKidSpeed.begin();
    m_flywheelKidSpeed.write32(Settings.getFlywheelKidSpeed());

    m_flywheelLudicrousSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_flywheelLudicrousSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_flywheelLudicrousSpeed.setFixedLen(4);
    m_flywheelLudicrousSpeed.setUserDescriptor("Flywheel Ludicrous Speed");
    m_flywheelLudicrousSpeed.setWriteCallback(onFlywheelLudicrousSpeedWriteCallback);
    m_flywheelLudicrousSpeed.begin();
    m_flywheelLudicrousSpeed.write32(Settings.getFlywheelLudicrousSpeed());

    m_flywheelTrimVariance.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_flywheelTrimVariance.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_flywheelTrimVariance.setFixedLen(4);
    m_flywheelTrimVariance.setUserDescriptor("Flywheel Trim Variance");
    m_flywheelTrimVariance.setWriteCallback(onFlywheelTrimVarianceWriteCallback);
    m_flywheelTrimVariance.begin();

    auto flywheelTrimVariance = Settings.getFlywheelTrimVariance();
    m_flywheelTrimVariance.write(&flywheelTrimVariance, 4);

    m_beltNormalSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_beltNormalSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_beltNormalSpeed.setFixedLen(4);
    m_beltNormalSpeed.setUserDescriptor("Belt Feed Normal Speed");
    m_beltNormalSpeed.setWriteCallback(onBeltNormalSpeedWriteCallback);
    m_beltNormalSpeed.begin();

    auto feedNormalSpeed = Settings.getFeedNormalSpeed();
    m_beltNormalSpeed.write(&feedNormalSpeed, 4);

    m_beltMediumSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_beltMediumSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_beltMediumSpeed.setFixedLen(4);
    m_beltMediumSpeed.setUserDescriptor("Belt Feed Medium Speed");
    m_beltMediumSpeed.setWriteCallback(onBeltMediumSpeedWriteCallback);
    m_beltMediumSpeed.begin();

    auto feedMediumSpeed = Settings.getFeedMediumSpeed();
    m_beltMediumSpeed.write(&feedMediumSpeed, 4);

    m_beltMaxSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_beltMaxSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_beltMaxSpeed.setFixedLen(4);
    m_beltMaxSpeed.setUserDescriptor("Belt Feed Max Speed");
    m_beltMaxSpeed.setWriteCallback(onBeltMaxSpeedWriteCallback);
    m_beltMaxSpeed.begin();

    auto feedMaxSpeed = Settings.getFeedMaxSpeed();
    m_beltMaxSpeed.write(&feedMaxSpeed, 4);
}