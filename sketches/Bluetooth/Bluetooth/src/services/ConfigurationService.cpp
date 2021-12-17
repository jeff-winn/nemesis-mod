#include "../Callbacks.h"
#include "../shared/Constants.h"
#include "ConfigurationService.h"
#include "CustomUuid.h"

ConfigurationService::ConfigurationService() : CustomBLEService(UUID128_SVC_CONFIGURATION) {
    m_flywheelNormalSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_NORMAL_SPEED);
    m_flywheelLowSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_LOW_SPEED);
    m_flywheelMaxSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_MAX_SPEED);
    m_flywheelTrimVariance = BLECharacteristic(UUID128_CHR_FLYWHEEL_TRIM_VARIANCE);
    m_pusherNormalSpeed = BLECharacteristic(UUID128_CHR_PUSHER_NORMAL_SPEED);
    m_pusherLowSpeed = BLECharacteristic(UUID128_CHR_PUSHER_LOW_SPEED);
    m_pusherMaxSpeed = BLECharacteristic(UUID128_CHR_PUSHER_MAX_SPEED);
    m_hopperLockEnabled = BLECharacteristic(UUID128_CHR_HOPPER_LOCK);
}

void onFlywheelLowSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(NRF52_CID_SET_CONFIG, data, len, 1);
}

void onFlywheelNormalSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(NRF52_CID_SET_CONFIG, data, len, 2);
}

void onFlywheelMaxSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(NRF52_CID_SET_CONFIG, data, len, 3);
}

void onPusherNormalSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(NRF52_CID_SET_CONFIG, data, len, 4);
}

void onPusherLowSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(NRF52_CID_SET_CONFIG, data, len, 5);
}

void onPusherMaxSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
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

    m_flywheelLowSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_flywheelLowSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_flywheelLowSpeed.setFixedLen(4);
    m_flywheelLowSpeed.setUserDescriptor("Flywheel Low Speed");
    m_flywheelLowSpeed.setWriteCallback(onFlywheelLowSpeedWriteCallback);
    m_flywheelLowSpeed.begin();

    m_flywheelMaxSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_flywheelMaxSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_flywheelMaxSpeed.setFixedLen(4);
    m_flywheelMaxSpeed.setUserDescriptor("Flywheel Max Speed");
    m_flywheelMaxSpeed.setWriteCallback(onFlywheelMaxSpeedWriteCallback);
    m_flywheelMaxSpeed.begin();

    m_flywheelTrimVariance.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_flywheelTrimVariance.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_flywheelTrimVariance.setFixedLen(4);
    m_flywheelTrimVariance.setUserDescriptor("Flywheel Trim Variance");
    m_flywheelTrimVariance.setWriteCallback(onFlywheelTrimVarianceWriteCallback);
    m_flywheelTrimVariance.begin();

    m_pusherNormalSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_pusherNormalSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_pusherNormalSpeed.setFixedLen(4);
    m_pusherNormalSpeed.setUserDescriptor("Pusher Normal Speed");
    m_pusherNormalSpeed.setWriteCallback(onPusherNormalSpeedWriteCallback);
    m_pusherNormalSpeed.begin();

    m_pusherLowSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_pusherLowSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_pusherLowSpeed.setFixedLen(4);
    m_pusherLowSpeed.setUserDescriptor("Pusher Low Speed");
    m_pusherLowSpeed.setWriteCallback(onPusherLowSpeedWriteCallback);
    m_pusherLowSpeed.begin();

    m_pusherMaxSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_pusherMaxSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_pusherMaxSpeed.setFixedLen(4);
    m_pusherMaxSpeed.setUserDescriptor("Pusher Max Speed");
    m_pusherMaxSpeed.setWriteCallback(onPusherMaxSpeedWriteCallback);
    m_pusherMaxSpeed.begin();

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

void ConfigurationService::setFlywheelLowSpeed(uint32_t value) {
    m_flywheelLowSpeed.write32(value);
}

void ConfigurationService::setFlywheelMaxSpeed(uint32_t value) {
    m_flywheelMaxSpeed.write32(value);
}

void ConfigurationService::setFlywheelTrimVariance(float value) {
    m_flywheelTrimVariance.write(&value, 4);
}

void ConfigurationService::setPusherNormalSpeed(uint32_t value) {
    m_pusherNormalSpeed.write32(value);
}

void ConfigurationService::setPusherLowSpeed(uint32_t value) {
    m_pusherLowSpeed.write32(value);
}

void ConfigurationService::setPusherMaxSpeed(uint32_t value) {
    m_pusherMaxSpeed.write32(value);
}

void ConfigurationService::setHopperLockEnabled(bool value) {
    if (value) {
        m_hopperLockEnabled.write8(0xFF);
    }
    else {
        m_hopperLockEnabled.write8(0x00);
    }
}