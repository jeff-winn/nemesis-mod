#ifndef BLE_CONTROLLER_H
#define BLE_CONTROLLER_H

#include <bluefruit.h>
#include "services/BlasterService.h"
#include "services/ConfigurationService.h"
#include "Callbacks.h"

// Provides a controller for the on-board bluetooth module.
class BLEController {
    public:
        BLEController();
        ~BLEController();

        void init(RemoteCommandReceivedCallback callback);
        void startAdvertising();

        void clearBonds();

    private:
        BlasterService m_blasterService;
        ConfigurationService m_configService;

        BLEDis m_discoveryService;
};

extern BLEController BLE;

#endif /* BLE_CONTROLLER_H */