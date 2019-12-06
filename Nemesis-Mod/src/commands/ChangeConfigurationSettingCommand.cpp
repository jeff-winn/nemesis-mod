#include "../BitConverter.h"
#include "../Log.h"
#include "ChangeConfigurationSettingCommand.h"

ChangeConfigurationSettingCommand::ChangeConfigurationSettingCommand(uint8_t subtype) : ConfigurationCommand() {
    m_subtype = subtype;
}

void ChangeConfigurationSettingCommand::handleImpl(uint8_t* data, uint16_t len) { 
    switch (m_subtype) {
        case 1: {
            auto value = getInt32ValueFromPacket(data);
            Settings.setFlywheelNormalSpeed(value);

            Log.println(value);
            Log.println("Changed flywheel normal speed.");
            break;
        }
        case 2: {
            auto value = getInt32ValueFromPacket(data);
            Settings.setFlywheelMediumSpeed(value);

            Log.println("Changed flywheel medium speed.");
            break;
        }
        case 3: {
            auto value = getInt32ValueFromPacket(data);
            Settings.setFlywheelMaxSpeed(value);

            Log.println("Changed flywheel max speed.");
            break;
        }
        case 4: {
            auto value = getInt32ValueFromPacket(data);
            Settings.setFeedNormalSpeed(value);

            Log.println("Changed feed normal speed.");
            break;
        }
        case 5: {
            auto value = getInt32ValueFromPacket(data);
            Settings.setFeedMediumSpeed(value);

            Log.println("Changed feed medium speed.");
            break;
        }
        case 6: {
            auto value = getInt32ValueFromPacket(data);
            Settings.setFeedMaxSpeed(value);

            Log.println("Changed feed max speed.");
            break;
        }
        case 7: {
            auto value = getFloatValueFromPacket(data);
            Settings.setFlywheelTrimVariance(value);

            Log.println(value);
            Log.println("Changed flywheel trim variance.");
            break;
        }
    }
}

int ChangeConfigurationSettingCommand::getInt32ValueFromPacket(uint8_t* data) {
    return Convert.toInt32(data);
}

float ChangeConfigurationSettingCommand::getFloatValueFromPacket(uint8_t* data) {
    return Convert.toFloat(data);
}