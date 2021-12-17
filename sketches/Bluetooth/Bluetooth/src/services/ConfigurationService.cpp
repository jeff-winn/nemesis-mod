#include "../Callbacks.h"
#include "../shared/Constants.h"
#include "ConfigurationService.h"
#include "CustomUuid.h"

ConfigurationService::ConfigurationService() : CustomBLEService(UUID128_SVC_CONFIGURATION) {
    m_flywheelNormalSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_NORMAL_SPEED);
    m_flywheelKidSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_KID_SPEED);
    m_flywheelLudicrousSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_LUDICROUS_SPEED);
    m_flywheelTrimVariance = BLECharacteristic(UUID128_CHR_FLYWHEEL_TRIM_VARIANCE);
    m_beltNormalSpeed = BLECharacteristic(UUID128_CHR_BELT_NORMAL_SPEED);
    m_beltLowSpeed = BLECharacteristic(UUID128_CHR_BELT_LOW_SPEED);
    m_beltMaxSpeed = BLECharacteristic(UUID128_CHR_BELT_MAX_SPEED);
    m_hopperLockEnabled = BLECharacteristic(UUID128_CHR_HOPPER_LOCK);
}

void onFlywheelKidSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(NRF52_CID_SET_CONFIG, data, len, 1);
}

void onFlywheelNormalSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(NRF52_CID_SET_CONFIG, data, len, 2);
}

void onFlywheelLudicrousSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(NRF52_CID_SET_CONFIG, data, len, 3);
}

void onBeltNormalSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(NRF52_CID_SET_CONFIG, data, len, 4);
}

void onBeltMediumSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(NRF52_CID_SET_CONFIG, data, len, 5);
}

void onBeltMaxSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(NRF52_CID_SET_CONFIG, data, len, 6);
}

void onFlywheelTrimVarianceWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(NRF52_CID_SET_CONFIG, data, len, 7);
}

void onHopperLockEnabledWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(NRF52_CID_SET_CONFIG, data, len, 8);
}

void ConfigurationService::init() {
    m_flywheelNormalSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_flywheelNormalSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_flywheelNormalSpeed.setFixedLen(4);
    m_flywheelNormalSpeed.setUserDescriptor("Flywheel Normal Speed");
    m_flywheelNormalSpeed.setWriteCallback(onFlywheelNormalSpeedWriteCallback);
    m_flywheelNormalSpeed.begin();

    m_flywheelKidSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_flywheelKidSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_flywheelKidSpeed.setFixedLen(4);
    m_flywheelKidSpeed.setUserDescriptor("Flywheel Kid Speed");
    m_flywheelKidSpeed.setWriteCallback(onFlywheelKidSpeedWriteCallback);
    m_flywheelKidSpeed.begin();

    m_flywheelLudicrousSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_flywheelLudicrousSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_flywheelLudicrousSpeed.setFixedLen(4);
    m_flywheelLudicrousSpeed.setUserDescriptor("Flywheel Ludicrous Speed");
    m_flywheelLudicrousSpeed.setWriteCallback(onFlywheelLudicrousSpeedWriteCallback);
    m_flywheelLudicrousSpeed.begin();

    m_flywheelTrimVariance.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_flywheelTrimVariance.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_flywheelTrimVariance.setFixedLen(4);
    m_flywheelTrimVariance.setUserDescriptor("Flywheel Trim Variance");
    m_flywheelTrimVariance.setWriteCallback(onFlywheelTrimVarianceWriteCallback);
    m_flywheelTrimVariance.begin();

    m_beltNormalSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_beltNormalSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_beltNormalSpeed.setFixedLen(4);
    m_beltNormalSpeed.setUserDescriptor("Pusher Normal Speed");
    m_beltNormalSpeed.setWriteCallback(onBeltNormalSpeedWriteCallback);
    m_beltNormalSpeed.begin();

    m_beltLowSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_beltLowSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_beltLowSpeed.setFixedLen(4);
    m_beltLowSpeed.setUserDescriptor("Pusher Low Speed");
    m_beltLowSpeed.setWriteCallback(onBeltMediumSpeedWriteCallback);
    m_beltLowSpeed.begin();

    m_beltMaxSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_beltMaxSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_beltMaxSpeed.setFixedLen(4);
    m_beltMaxSpeed.setUserDescriptor("Pusher Max Speed");
    m_beltMaxSpeed.setWriteCallback(onBeltMaxSpeedWriteCallback);
    m_beltMaxSpeed.begin();

    m_hopperLockEnabled.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_hopperLockEnabled.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_hopperLockEnabled.setFixedLen(1);
    m_hopperLockEnabled.setUserDescriptor("Mag Lock Enabled");
    m_hopperLockEnabled.setWriteCallback(onHopperLockEnabledWriteCallback);
    m_hopperLockEnabled.begin();
}

void ConfigurationService::setFlywheelNormalSpeed(uint32_t value) {
    m_flywheelNormalSpeed.write32(value);
}

void ConfigurationService::setFlywheelKidSpeed(uint32_t value) {
    m_flywheelKidSpeed.write32(value);
}

void ConfigurationService::setFlywheelLudicrousSpeed(uint32_t value) {
    m_flywheelLudicrousSpeed.write32(value);
}

void ConfigurationService::setFlywheelTrimVariance(float value) {
    m_flywheelTrimVariance.write(&value, 4);
}

void ConfigurationService::setBeltNormalSpeed(uint32_t value) {
    m_beltNormalSpeed.write32(value);
}

void ConfigurationService::setBeltLowSpeed(uint32_t value) {
    m_beltLowSpeed.write32(value);
}

void ConfigurationService::setBeltMaxSpeed(uint32_t value) {
    m_beltMaxSpeed.write32(value);
}

void ConfigurationService::setHopperLockEnabled(bool value) {
    if (value) {
        m_hopperLockEnabled.write8(0xFF);
    }
    else {
        m_hopperLockEnabled.write8(0x00);
    }
}