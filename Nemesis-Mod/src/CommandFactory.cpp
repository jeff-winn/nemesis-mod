#include "CommandFactory.h"
#include <cstddef>

Command* CommandFactory::createCommand(uint8_t type, uint8_t subtype) {
    // switch (type) {
    //     case 10: {
    //         return new ChangeConfigurationSettingCommand(subtype);
    //     }
    //     case 100: {
    //         return new BeltSpeedCommand(&Belt);
    //     }
    //     case 200: {
    //         return new FlywheelSpeedCommand(&Flywheels);
    //     }
    //     case 201: {
    //         return new FlywheelTrimAdjustmentCommand(subtype, &Flywheels);        
    //     }
    // }

    return NULL;
}