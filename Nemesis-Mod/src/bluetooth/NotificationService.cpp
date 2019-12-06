#include "NotificationService.h"
#include "CustomUuid.h"

NotificationService::NotificationService() : CustomBLEService(UUID128_SVC_NOTIFICATIONS) {
    _flywheelM1CurrentMilliamps = BLECharacteristic(UUID128_CHR_FLYWHEEL_M1_CURRENT_MILLIAMPS);
    _flywheelM2CurrentMilliamps = BLECharacteristic(UUID128_CHR_FLYWHEEL_M2_CURRENT_MILLIAMPS);
    _beltM1CurrentMilliamps = BLECharacteristic(UUID128_CHR_BELT_M1_CURRENT_MILLIAMPS);
}

void NotificationService::init() {
    _flywheelM1CurrentMilliamps.setProperties(CHR_PROPS_NOTIFY);
    _flywheelM1CurrentMilliamps.setPermission(SECMODE_ENC_NO_MITM, SECMODE_NO_ACCESS);
    _flywheelM1CurrentMilliamps.setFixedLen(4);
    _flywheelM1CurrentMilliamps.setUserDescriptor("Flywheel M1 Current (in milliamps)");
    _flywheelM1CurrentMilliamps.begin();
    _flywheelM1CurrentMilliamps.write32(0);

    _flywheelM2CurrentMilliamps.setProperties(CHR_PROPS_NOTIFY);
    _flywheelM2CurrentMilliamps.setPermission(SECMODE_ENC_NO_MITM, SECMODE_NO_ACCESS);
    _flywheelM2CurrentMilliamps.setFixedLen(4);
    _flywheelM2CurrentMilliamps.setUserDescriptor("Flywheel M2 Current (in milliamps)");
    _flywheelM2CurrentMilliamps.begin();
    _flywheelM2CurrentMilliamps.write32(0);

    _beltM1CurrentMilliamps.setProperties(CHR_PROPS_NOTIFY);
    _beltM1CurrentMilliamps.setPermission(SECMODE_ENC_NO_MITM, SECMODE_NO_ACCESS);
    _beltM1CurrentMilliamps.setFixedLen(4);
    _beltM1CurrentMilliamps.setUserDescriptor("Belt M1 Current (in milliamps)");
    _beltM1CurrentMilliamps.begin();
    _beltM1CurrentMilliamps.write32(0);
}

void NotificationService::notifyBeltCurrentMilliamps(uint32_t m1) {
    _beltM1CurrentMilliamps.notify32(m1);
}

void NotificationService::notifyFlywheelCurrentMilliamps(uint32_t m1, uint32_t m2) {
    _flywheelM1CurrentMilliamps.notify32(m1);
    _flywheelM2CurrentMilliamps.notify32(m2);    
}