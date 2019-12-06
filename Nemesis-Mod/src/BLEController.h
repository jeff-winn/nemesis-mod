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
        BlasterService _blasterService;
        ConfigurationService _configService;
        NotificationService _notificationService;

        BLEDis _discoveryService;

        uint32_t lastFlywheelMilliampsNotifyAtMillis;
        uint32_t lastBeltMilliampsNotifyAtMillis;
};

extern BLEController BLE;

#endif /* BLUETOOTH_CONTROLLER_H */