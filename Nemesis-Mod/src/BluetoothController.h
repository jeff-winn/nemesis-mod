#ifndef BLUETOOTH_CONTROLLER_H
#define BLUETOOTH_CONTROLLER_H

#include <bluefruit.h>
#include "bluetooth/BlasterService.h"
#include "bluetooth/ConfigurationService.h"

// Provides a controller for the on-board bluetooth module.
class BluetoothController {
    public:
        BluetoothController();

        ~BluetoothController();

        void init();
        void startAdvertising();

        void clearBonds();
        
    private:
        BlasterService _blasterService;
        ConfigurationService _configService;

        BLEDis _discoveryService;
};

#endif /* BLUETOOTH_CONTROLLER_H */