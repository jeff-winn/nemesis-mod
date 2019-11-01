#ifndef NERF_BLE_SERVICE_H
#define NERF_BLE_SERVICE_H

#include <bluefruit.h>
#include "CustomUuid.h"

class NerfBLEService : public BLEService {
    public:
        NerfBLEService();
        void init(BLECharacteristic::write_cb_t onFlywheelSpeedChangedCallback, BLECharacteristic::write_cb_t onBeltSpeedChangedCallback);

    private:
        BLECharacteristic _flywheelSpeed;
        BLECharacteristic _beltSpeed;
};

#endif