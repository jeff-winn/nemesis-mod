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
        ~BLEController() = default;

        void setCallback(RemoteCommandReceivedCallback callback) const;
        void init(const char* name);

        void setCharacteristic(uint8_t characteristicId, uint8_t *data, uint8_t len);
        void startAdvertising();

        void clearBonds();
        void setPin(const char* pin);

    protected:
        void setFlywheelSpeed(uint8_t* data);
        void setPusherSpeed(uint8_t* data);
        void setFlywheelM1TrimSpeed(uint8_t* data, uint8_t len);
        void setFlywheelM2TrimSpeed(uint8_t* data, uint8_t len);
        void setFlywheelNormalSpeed(uint8_t* data);
        void setFlywheelLowSpeed(uint8_t* data);
        void setFlywheelMaxSpeed(uint8_t* data);
        void setFlywheelTrimVariance(uint8_t* data);
        void setPusherNormalSpeed(uint8_t* data);
        void setPusherLowSpeed(uint8_t* data);
        void setPusherMaxSpeed(uint8_t* data);
        void setHopperLockEnabled(uint8_t* data);

    private:
        BlasterService m_blasterService;
        ConfigurationService m_configService;

        BLEDis m_discoveryService;
};

extern BLEController BLE;

#endif /* BLE_CONTROLLER_H */