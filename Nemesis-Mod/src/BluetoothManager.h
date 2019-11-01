#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include "services/NerfBLEService.h"

// Provides an adapter to the onboard bluetooth module.
class BluetoothManager {
    public:
        BluetoothManager();

        ~BluetoothManager();

        void beginInit(BLECharacteristic::write_cb_t onFlywheelSpeedChangedCallback, BLECharacteristic::write_cb_t onBeltSpeedChangedCallback);
        void endInit();

    private:
        NerfBLEService _nerfService;
        BLEDis _discoveryService;
};

#endif