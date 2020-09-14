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
            Settings.setFlywheelKidSpeed(value);

            Log.println(value);
            Log.println("Changed flywheel kid speed.");
            break;
        }
        case 2: {
            auto value = getInt32ValueFromPacket(data);
            Settings.setFlywheelNormalSpeed(value);

            Log.println(value);
            Log.println("Changed flywheel normal speed.");
            break;
        }
        case 3: {
            auto value = getInt32ValueFromPacket(data);
            Settings.setFlywheelLudicrousSpeed(value);

            Log.println(value);
            Log.println("Changed flywheel ludicrous speed.");
            break;
        }
        case 4: {
            auto value = getInt32ValueFromPacket(data);
            Settings.setFeedNormalSpeed(value);

            Log.println(value);
            Log.println("Changed feed normal speed.");
            break;
        }
        case 5: {
            auto value = getInt32ValueFromPacket(data);
            Settings.setFeedMediumSpeed(value);

            Log.println(value);
            Log.println("Changed feed medium speed.");
            break;
        }
        case 6: {
            auto value = getInt32ValueFromPacket(data);
            Settings.setFeedMaxSpeed(value);

            Log.println(value);
            Log.println("Changed feed max speed.");
            break;
        }
        case 7: {
            auto value = getFloatValueFromPacket(data);
            Settings.setFlywheelTrimVariance(value);

            Log.println(value, 5);
            Log.println("Changed flywheel trim variance.");
            break;
        }
        case 8: {
            auto value = getByteValueFromPacket(data);
            Settings.setIsHopperLockEnabled(value != 0);

            Log.println(value);
            Log.println("Changed hopper lock enabled.");
            break;
        }
    }
}

byte ChangeConfigurationSettingCommand::getByteValueFromPacket(const uint8_t* data) {
    return data[0];
}

int ChangeConfigurationSettingCommand::getInt32ValueFromPacket(const uint8_t* data) {
    return Convert.toInt32(data);
}

float ChangeConfigurationSettingCommand::getFloatValueFromPacket(const uint8_t* data) {
    return Convert.toFloat(data);
}