#ifndef CONFIGURATION_SERVICE_H
#define CONFIGURATION_SERVICE_H

#include "CustomBLEService.h"

class ConfigurationService : public CustomBLEService {
    public:
        ConfigurationService();

        void init() override;
    
    private:
        BLECharacteristic m_flywheelNormalSpeed;
        BLECharacteristic m_flywheelTrimVariance;
        BLECharacteristic m_beltMaxSpeed;
};

#endif /* CONFIGURATION_SERVICE_H */