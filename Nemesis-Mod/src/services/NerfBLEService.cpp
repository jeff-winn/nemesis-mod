#include "NerfBLEService.h"

NerfBLEService::NerfBLEService() : BLEService(UUID128_SVC_NERF_BLASTER) {
    _flywheelSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_SPEED);
    _beltSpeed = BLECharacteristic(UUID128_CHR_BELT_SPEED);
}

void NerfBLEService::init(BLECharacteristic::write_cb_t onFlywheelSpeedChangedCallback, BLECharacteristic::write_cb_t onBeltSpeedChangedCallback) {
    _flywheelSpeed.setWriteCallback(onFlywheelSpeedChangedCallback);
    _beltSpeed.setWriteCallback(onBeltSpeedChangedCallback);
}