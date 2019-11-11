#ifndef BLUETOOTH_CONTROLLER_H
#define BLUETOOTH_CONTROLLER_H

#include <bluefruit.h>
#include "BlasterService.h"
#include "ConfigurationService.h"

// Provides a controller for the on-board bluetooth module.
class BluetoothController {
    public:
        BluetoothController();

        ~BluetoothController();

        void init();
        void startAdvertising();
        
    private:
        BlasterService _blasterService;
        ConfigurationService _configService;

        BLEDis _discoveryService;
};

#endif /* BLUETOOTH_CONTROLLER_H */