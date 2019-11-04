#ifndef NERF_BLE_SERVICE_H
#define NERF_BLE_SERVICE_H

#include <bluefruit.h>
#include "CustomUuid.h"

class CustomBLEService : public BLEService {
    public:
        CustomBLEService();

    private:
        BLECharacteristic _flywheelSpeed;
};

#endif