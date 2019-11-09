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

void onFlywheelSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len);
void onBeltSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len);

#endif /* BLASTER_SPEED_SERVICE_H */