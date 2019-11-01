#ifndef CUSTOM_BLE_SERVICE_H
#define CUSTOM_BLE_SERVICE_H

#include <bluefruit.h>
#include "CustomUuid.h"

class CustomBLEService : public BLEService {
    public:
        CustomBLEService();

    private:
        BLECharacteristic _flywheelSpeed;
        BLECharacteristic _beltSpeed;
};

#endif