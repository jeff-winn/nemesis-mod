#ifndef BLUETOOTH_CONTROLLER_H
#define BLUETOOTH_CONTROLLER_H

#include <bluefruit.h>
#include "bluetooth/BlasterService.h"
#include "bluetooth/ConfigurationService.h"
#include "bluetooth/NotificationService.h"

// Provides a controller for the on-board bluetooth module.
class BLEController {
    public:
        BLEController();

        ~BLEController();

        void init();
        void startAdvertising();

        void clearBonds();

        void notifyFlywheelCurrentMilliamps(uint32_t m1, uint32_t m2, bool isActive);

        void notifyBeltCurrentMilliamps(uint32_t m1, bool isActive);
    
    protected:
        bool shouldSendNotification(uint32_t lastNotificationAtMillis, uint32_t interval);

    private:
        BlasterService m_blasterService;
        ConfigurationService m_configService;
        NotificationService m_notificationService;

        BLEDis m_discoveryService;

        uint32_t m_lastFlywheelMilliampsNotifyAtMillis;
        uint32_t m_lastBeltMilliampsNotifyAtMillis;
};

extern BLEController BLE;

#endif /* BLUETOOTH_CONTROLLER_H */