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

        void setCharacteristic(const uint8_t characteristicId, const uint8_t *data);
        void startAdvertising();

        void clearBonds();
        void setPin(const char* pin);

    protected:
        void setFlywheelSpeed(const uint8_t* data);
        void setPusherSpeed(const uint8_t* data);
        void setFlywheelM1TrimSpeed(const uint8_t* data);
        void setFlywheelM2TrimSpeed(const uint8_t* data);
        void setFlywheelNormalSpeed(const uint8_t* data);
        void setFlywheelLowSpeed(const uint8_t* data);
        void setFlywheelMaxSpeed(const uint8_t* data);
        void setFlywheelTrimVariance(const uint8_t* data);
        void setPusherNormalSpeed(const uint8_t* data);
        void setPusherLowSpeed(const uint8_t* data);
        void setPusherMaxSpeed(const uint8_t* data);
        void setHopperLockEnabled(const uint8_t* data);

    private:
        BlasterService m_blasterService;
        ConfigurationService m_configService;

        BLEDis m_discoveryService;
};

extern BLEController BLE;

#endif /* BLE_CONTROLLER_H */