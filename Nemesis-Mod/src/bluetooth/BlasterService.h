#ifndef BLASTER_SERVICE_H
#define BLASTER_SERVICE_H

#include <bluefruit.h>
#include "CustomBLEService.h"

class BlasterService : public CustomBLEService {
    public:
        BlasterService();

        void init() override;

        void notifyFlywheelCurrentMilliamps(uint32_t m1, uint32_t m2);

        void notifyBeltCurrentMilliamps(uint32_t m1);

    private:
        BLECharacteristic _flywheelSpeed;
        BLECharacteristic _flywheelM1TrimSpeed;
        BLECharacteristic _flywheelM2TrimSpeed;
        BLECharacteristic _beltSpeed;

        BLECharacteristic _flywheelM1CurrentMilliamps;
        BLECharacteristic _flywheelM2CurrentMilliamps;
        BLECharacteristic _beltM1CurrentMilliamps;
};

#endif /* BLASTER_SERVICE_H */