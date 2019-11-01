#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include "services/CustomBLEService.h"

// Provides an adapter to the onboard bluetooth module.
class BluetoothManager {
    public:
        BluetoothManager();

        ~BluetoothManager();

        void beginInit();
        void endInit();
};

#endif