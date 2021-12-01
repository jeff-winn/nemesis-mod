#ifndef CONFIGURATION_SERVICE_H
#define CONFIGURATION_SERVICE_H

#include "CustomBLEService.h"

class ConfigurationService : public CustomBLEService {
    public:
        ConfigurationService();

        void init() override;

        void setFlywheelNormalSpeed(uint32_t value);
        void setFlywheelKidSpeed(uint32_t value);
        void setFlywheelLudicrousSpeed(uint32_t value);
        void setFlywheelTrimVariance(float value);
        void setBeltNormalSpeed(uint32_t value);
        void setBeltMediumSpeed(uint32_t value);
        void setBeltMaxSpeed(uint32_t value);
        void setHopperLockEnabled(bool value);
    
    private:
        BLECharacteristic m_flywheelNormalSpeed;
        BLECharacteristic m_flywheelKidSpeed;
        BLECharacteristic m_flywheelLudicrousSpeed;
        BLECharacteristic m_flywheelTrimVariance;
        BLECharacteristic m_beltNormalSpeed;
        BLECharacteristic m_beltMediumSpeed;
        BLECharacteristic m_beltMaxSpeed;
        BLECharacteristic m_hopperLockEnabled;
};

#endif /* CONFIGURATION_SERVICE_H */