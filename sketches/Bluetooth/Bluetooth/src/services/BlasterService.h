#ifndef BLASTER_SERVICE_H
#define BLASTER_SERVICE_H

#include <bluefruit.h>
#include "CustomBLEService.h"

class BlasterService : public CustomBLEService {
    public:
        BlasterService();

        void init() override;

        void setFlywheelSpeed(uint8_t value);
        void setBeltSpeed(uint8_t value);
        void setFlywheelM1TrimSpeed(float value);
        void setFlywheelM2TrimSpeed(float value);

    private:
        BLECharacteristic m_flywheelSpeed;
        BLECharacteristic m_flywheelM1TrimSpeed;
        BLECharacteristic m_flywheelM2TrimSpeed;
        BLECharacteristic m_beltSpeed;
};

#endif /* BLASTER_SERVICE_H */