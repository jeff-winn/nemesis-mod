#include "CustomBLEService.h"

CustomBLEService::CustomBLEService() : BLEService(UUID128_SVC_NERF_BLASTER) {
    _flywheelSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_SPEED);
}