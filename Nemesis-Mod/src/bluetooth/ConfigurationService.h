#ifndef CONFIGURATION_SERVICE_H
#define CONFIGURATION_SERVICE_H

#include "CustomBLEService.h"

class ConfigurationService : public CustomBLEService {
    public:
        ConfigurationService();

        void init() override;
    
    private:
        BLECharacteristic _flywheelNormalSpeed;
        BLECharacteristic _flywheelTrimVariance;
        BLECharacteristic _beltMaxSpeed;
};

#endif /* CONFIGURATION_SERVICE_H */