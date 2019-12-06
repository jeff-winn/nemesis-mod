#ifndef NOTIFICATION_SERVICE_H
#define NOTIFICATION_SERVICE_H

#include "CustomBLEService.h"

class NotificationService : public CustomBLEService  {
    public:
        NotificationService();

        void init() override;

        void notifyFlywheelCurrentMilliamps(uint32_t m1, uint32_t m2);
        void notifyBeltCurrentMilliamps(uint32_t m1);

    private:
        BLECharacteristic _flywheelM1CurrentMilliamps;
        BLECharacteristic _flywheelM2CurrentMilliamps;
        BLECharacteristic _beltM1CurrentMilliamps;
};

#endif /* NOTIFICATION_SERVICE_H */