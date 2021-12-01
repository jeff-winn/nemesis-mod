#include "../Callbacks.h"
#include "../shared/Constants.h"
#include "BlasterService.h"
#include "CustomUuid.h"

BlasterService::BlasterService() : CustomBLEService(UUID128_SVC_NERF_BLASTER) {
    m_flywheelSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_SPEED);
    m_flywheelM1TrimSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_M1TRIM_SPEED);
    m_flywheelM2TrimSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_M2TRIM_SPEED);
    m_beltSpeed = BLECharacteristic(UUID128_CHR_BELT_SPEED);
}

void onFlywheelSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(NRF52_CID_FLYWHEEL_SPEED, data, len, 0);
}

void onFlywheelM1TrimAdjustmentWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(NRF52_CID_FLYWHEEL_TRIM, data, len, 1);
}

void onFlywheelM2TrimAdjustmentWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(NRF52_CID_FLYWHEEL_TRIM, data, len, 2); 
}

void onBeltSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
    NotifyBluetoothCommandReceived(NRF52_CID_BELT_SPEED, data, len, 0);
}

void BlasterService::init() {  
    m_flywheelSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_flywheelSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_flywheelSpeed.setFixedLen(1);
    m_flywheelSpeed.setUserDescriptor("Flywheel Speed");
    m_flywheelSpeed.setWriteCallback(onFlywheelSpeedWriteCallback);
    m_flywheelSpeed.begin();

    m_flywheelM1TrimSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_flywheelM1TrimSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_flywheelM1TrimSpeed.setFixedLen(4);
    m_flywheelM1TrimSpeed.setUserDescriptor("Flywheel M1 Trim Speed");
    m_flywheelM1TrimSpeed.setWriteCallback(onFlywheelM1TrimAdjustmentWriteCallback);
    m_flywheelM1TrimSpeed.begin();

    m_flywheelM2TrimSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_flywheelM2TrimSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_flywheelM2TrimSpeed.setFixedLen(4);
    m_flywheelM2TrimSpeed.setUserDescriptor("Flywheel M2 Trim Speed");
    m_flywheelM2TrimSpeed.setWriteCallback(onFlywheelM2TrimAdjustmentWriteCallback);
    m_flywheelM2TrimSpeed.begin();

    m_beltSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
    m_beltSpeed.setPermission(SECMODE_ENC_NO_MITM, SECMODE_ENC_NO_MITM);
    m_beltSpeed.setFixedLen(1);
    m_beltSpeed.setUserDescriptor("Belt Speed");
    m_beltSpeed.setWriteCallback(onBeltSpeedWriteCallback);
    m_beltSpeed.begin();
}

void BlasterService::setFlywheelSpeed(uint8_t value) {
    m_flywheelSpeed.write8(value);
}

void BlasterService::setBeltSpeed(uint8_t value) {
    m_beltSpeed.write8(value);
}

void BlasterService::setFlywheelM1TrimSpeed(float value) {
    m_flywheelM1TrimSpeed.write(&value, 4);
}

void BlasterService::setFlywheelM2TrimSpeed(float value) {    
    m_flywheelM2TrimSpeed.write(&value, 4);
}