#include "CommandFactory.h"

#include <cstddef>
#include "commands/BTReadyCommand.h"
#include "commands/ChangeConfigurationSettingCommand.h"
#include "commands/FlywheelSpeedCommand.h"
#include "commands/FlywheelTrimAdjustmentCommand.h"
#include "commands/PusherSpeedCommand.h"
#include "shared/Constants.h"

Command* CommandFactory::createCommand(const uint8_t type, const uint8_t subtype) {
    switch (type) {
        case NRF52_CID_SET_CONFIG:
            return new ChangeConfigurationSettingCommand(subtype);
        
        case NRF52_CID_PUSHER_SPEED:
            return new PusherSpeedCommand(&Pusher);
        
        case NRF52_CID_FLYWHEEL_SPEED:
            return new FlywheelSpeedCommand(&Flywheels);
        
        case NRF52_CID_FLYWHEEL_TRIM:
            return new FlywheelTrimAdjustmentCommand(subtype, &Flywheels);        
        
        case NRF52_CID_READY:
            return new BTReadyCommand();
        
    }

    return nullptr;
}