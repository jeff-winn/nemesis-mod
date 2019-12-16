#include "../BitConverter.h"
#include "../Log.h"
#include "ChangeConfigurationSettingCommand.h"

ChangeConfigurationSettingCommand::ChangeConfigurationSettingCommand(uint8_t subtype) : ConfigurationCommand() {
    m_subtype = subtype;
}

void ChangeConfigurationSettingCommand::handleImpl(uint8_t* data, uint16_t len) { 
    switch (m_subtype) {
        case 1: {
            auto flywheelKidSpeed = getInt32ValueFromPacket(data);
            Settings.setFlywheelKidSpeed(flywheelKidSpeed);

            Log.println(flywheelKidSpeed);
            Log.println("Changed flywheel kid speed.");
            break;
        }
        case 2: {
            auto flywheelNormalSpeed = getInt32ValueFromPacket(data);
            Settings.setFlywheelNormalSpeed(flywheelNormalSpeed);

            Log.println(flywheelNormalSpeed);
            Log.println("Changed flywheel normal speed.");
            break;
        }
        case 3: {
            auto flywheelLudicrousSpeed = getInt32ValueFromPacket(data);
            Settings.setFlywheelLudicrousSpeed(flywheelLudicrousSpeed);

            Log.println(flywheelLudicrousSpeed);
            Log.println("Changed flywheel ludicrous speed.");
            break;
        }
        case 4: {
            auto feedNormalSpeed = getInt32ValueFromPacket(data);
            Settings.setFeedNormalSpeed(feedNormalSpeed);

            Log.println(feedNormalSpeed);
            Log.println("Changed feed normal speed.");
            break;
        }
        case 5: {
            auto feedMediumSpeed = getInt32ValueFromPacket(data);
            Settings.setFeedMediumSpeed(feedMediumSpeed);

            Log.println(feedMediumSpeed);
            Log.println("Changed feed medium speed.");
            break;
        }
        case 6: {
            auto feedMaxSpeed = getInt32ValueFromPacket(data);
            Settings.setFeedMaxSpeed(feedMaxSpeed);

            Log.println(feedMaxSpeed);
            Log.println("Changed feed max speed.");
            break;
        }
        case 7: {
            auto flywheelTrimVariance = getFloatValueFromPacket(data);
            Settings.setFlywheelTrimVariance(flywheelTrimVariance);

            Log.println(flywheelTrimVariance);
            Log.println("Changed flywheel trim variance.");
            break;
        }
    }
}

int ChangeConfigurationSettingCommand::getInt32ValueFromPacket(const uint8_t* data) {
    return Convert.toInt32(data);
}

float ChangeConfigurationSettingCommand::getFloatValueFromPacket(const uint8_t* data) {
    return Convert.toFloat(data);
}