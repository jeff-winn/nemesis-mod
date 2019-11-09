#ifndef BLASTER_SPEED_SERVICE_H
#define BLASTER_SPEED_SERVICE_H

#include <bluefruit.h>
#include "CustomBLEService.h"

class BlasterSpeedService : public CustomBLEService {
    public:
        BlasterSpeedService();

        void init() override;

    private:
        BLECharacteristic _flywheelSpeed;
        BLECharacteristic _beltSpeed;
};

#endif /* BLASTER_SPEED_SERVICE_H */