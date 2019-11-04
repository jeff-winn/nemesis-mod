#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include "services/CustomBLEService.h"

// Provides a controller for the on-board bluetooth module.
class BluetoothController {
    public:
        BluetoothController();

        ~BluetoothController();

        void beginInit();
        void endInit();

    private:
        CustomBLEService _customService;
        BLEDis _discoveryService;
};

#endif