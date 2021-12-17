#ifndef CONFIGURATION_SERVICE_H
#define CONFIGURATION_SERVICE_H

#include "CustomBLEService.h"

class ConfigurationService : public CustomBLEService {
    public:
        ConfigurationService();

        void init() override;

        void setFlywheelNormalSpeed(uint32_t value);
        void setFlywheelLowSpeed(uint32_t value);
        void setFlywheelMaxSpeed(uint32_t value);
        void setFlywheelTrimVariance(float value);
        void setBeltNormalSpeed(uint32_t value);
        void setBeltLowSpeed(uint32_t value);
        void setBeltMaxSpeed(uint32_t value);
        void setHopperLockEnabled(bool value);
    
    private:
        BLECharacteristic m_flywheelNormalSpeed;
        BLECharacteristic m_flywheelLowSpeed;
        BLECharacteristic m_flywheelMaxSpeed;
        BLECharacteristic m_flywheelTrimVariance;
        BLECharacteristic m_beltNormalSpeed;
        BLECharacteristic m_beltLowSpeed;
        BLECharacteristic m_beltMaxSpeed;
        BLECharacteristic m_hopperLockEnabled;
};

#endif /* CONFIGURATION_SERVICE_H */