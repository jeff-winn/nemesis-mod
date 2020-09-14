#include "NotificationService.h"
#include "CustomUuid.h"

NotificationService::NotificationService() : CustomBLEService(UUID128_SVC_NOTIFICATIONS) {
    m_flywheelM1CurrentMilliamps = BLECharacteristic(UUID128_CHR_FLYWHEEL_M1_CURRENT_MILLIAMPS);
    m_flywheelM2CurrentMilliamps = BLECharacteristic(UUID128_CHR_FLYWHEEL_M2_CURRENT_MILLIAMPS);
    m_beltM1CurrentMilliamps = BLECharacteristic(UUID128_CHR_BELT_M1_CURRENT_MILLIAMPS);
}

void NotificationService::init() {
    m_flywheelM1CurrentMilliamps.setProperties(CHR_PROPS_NOTIFY);
    m_flywheelM1CurrentMilliamps.setPermission(SECMODE_ENC_NO_MITM, SECMODE_NO_ACCESS);
    m_flywheelM1CurrentMilliamps.setFixedLen(4);
    m_flywheelM1CurrentMilliamps.setUserDescriptor("Flywheel M1 Current (mA)");
    m_flywheelM1CurrentMilliamps.begin();
    m_flywheelM1CurrentMilliamps.write32(0);

    m_flywheelM2CurrentMilliamps.setProperties(CHR_PROPS_NOTIFY);
    m_flywheelM2CurrentMilliamps.setPermission(SECMODE_ENC_NO_MITM, SECMODE_NO_ACCESS);
    m_flywheelM2CurrentMilliamps.setFixedLen(4);
    m_flywheelM2CurrentMilliamps.setUserDescriptor("Flywheel M2 Current (mA)");
    m_flywheelM2CurrentMilliamps.begin();
    m_flywheelM2CurrentMilliamps.write32(0);

    m_beltM1CurrentMilliamps.setProperties(CHR_PROPS_NOTIFY);
    m_beltM1CurrentMilliamps.setPermission(SECMODE_ENC_NO_MITM, SECMODE_NO_ACCESS);
    m_beltM1CurrentMilliamps.setFixedLen(4);
    m_beltM1CurrentMilliamps.setUserDescriptor("Belt M1 Current (mA)");
    m_beltM1CurrentMilliamps.begin();
    m_beltM1CurrentMilliamps.write32(0);
}

void NotificationService::notifyBeltCurrentMilliamps(uint32_t m1) {
    m_beltM1CurrentMilliamps.notify32(m1);
}

void NotificationService::notifyFlywheelCurrentMilliamps(uint32_t m1, uint32_t m2) {
    m_flywheelM1CurrentMilliamps.notify32(m1);
    m_flywheelM2CurrentMilliamps.notify32(m2);    
}