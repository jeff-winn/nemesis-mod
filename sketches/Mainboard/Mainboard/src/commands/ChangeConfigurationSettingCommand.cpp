#include "../shared/BitConverter.h"
#include "ChangeConfigurationSettingCommand.h"

ChangeConfigurationSettingCommand::ChangeConfigurationSettingCommand(uint8_t subtype) : ConfigurationCommand() {
    m_subtype = subtype;
}

void ChangeConfigurationSettingCommand::handleImpl(const uint8_t* data, const uint16_t len) { 
    switch (m_subtype) {
        case 1: {
            auto value = getInt32ValueFromPacket(data);
            Settings.setFlywheelLowSpeed(value);
            break;
        }
        case 2: {
            auto value = getInt32ValueFromPacket(data);
            Settings.setFlywheelNormalSpeed(value);
            break;
        }
        case 3: {
            auto value = getInt32ValueFromPacket(data);
            Settings.setFlywheelMaxSpeed(value);
            break;
        }
        case 4: {
            auto value = getInt32ValueFromPacket(data);
            Settings.setPusherNormalSpeed(value);
            break;
        }
        case 5: {
            auto value = getInt32ValueFromPacket(data);
            Settings.setPusherLowSpeed(value);
            break;
        }
        case 6: {
            auto value = getInt32ValueFromPacket(data);
            Settings.setPusherMaxSpeed(value);
            break;
        }
        case 7: {
            auto value = getFloatValueFromPacket(data);
            Settings.setFlywheelTrimVariance(value);
            break;
        }
        case 8: {
            auto value = getByteValueFromPacket(data);
            Settings.setIsHopperLockEnabled(value != 0);
            break;
        }
    }
}

byte ChangeConfigurationSettingCommand::getByteValueFromPacket(const uint8_t* data) const {
    return data[0];
}

int ChangeConfigurationSettingCommand::getInt32ValueFromPacket(const uint8_t* data) const {
    return Convert.toInt32(data);
}

float ChangeConfigurationSettingCommand::getFloatValueFromPacket(const uint8_t* data) const {
    return Convert.toFloat(data);
}