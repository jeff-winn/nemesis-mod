#ifndef BLE_CONTROLLER_H
#define BLE_CONTROLLER_H

#include <bluefruit.h>
#include "services/BlasterService.h"
#include "services/ConfigurationService.h"
#include "services/NotificationService.h"

// Occurs whenever a bluetooth command has been received.
void OnBluetoothCommandReceivedCallback(uint8_t type, uint8_t* data, uint16_t len, uint8_t subtype);

// Provides a controller for the on-board bluetooth module.
class BLEController {
    public:
        BLEController();
        ~BLEController();

        void init();
        void startAdvertising();

        void clearBonds();

        void onRemoteCommandReceived(uint8_t type, uint8_t subtype, uint8_t* data, uint8_t len);
        void notifyFlywheelCurrentMilliamps(uint32_t m1, uint32_t m2, bool isActive);

        void notifyBeltCurrentMilliamps(uint32_t m1, bool isActive);
    
    protected:
        bool shouldSendNotification(uint32_t lastNotificationAtMillis, uint32_t interval);

    private:
        BlasterService m_blasterService;
        ConfigurationService m_configService;

        BLEDis m_discoveryService;

        uint32_t m_lastFlywheelMilliampsNotifyAtMillis;
        uint32_t m_lastBeltMilliampsNotifyAtMillis;
};

extern BLEController BLE;

#endif /* BLE_CONTROLLER_H */