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

        void setCharacteristic(uint8_t characteristicId, uint8_t *data, uint8_t len);
        void startAdvertising();

        void clearBonds();
        void setPin(const char* pin);

    private:
        BlasterService m_blasterService;
        ConfigurationService m_configService;

        BLEDis m_discoveryService;
};

extern BLEController BLE;

#endif /* BLE_CONTROLLER_H */