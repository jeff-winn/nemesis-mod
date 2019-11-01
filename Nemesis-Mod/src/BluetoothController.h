#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include "services/NerfBLEService.h"

// Provides a controller for the on-board bluetooth module.
class BluetoothController {
    public:
        BluetoothController();

        ~BluetoothController();

        void beginInit(BLECharacteristic::write_cb_t onFlywheelSpeedChangedCallback, BLECharacteristic::write_cb_t onBeltSpeedChangedCallback);
        void endInit();

    private:
        NerfBLEService _nerfService;
        BLEDis _discoveryService;
};

#endif