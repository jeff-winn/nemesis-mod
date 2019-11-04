#include "ChangeConfigurationSettingCommand.h"
#include "../BitConverter.h"

void ChangeConfigurationSettingCommand::handleImpl(Packet_t packet) {
    auto id = packet.body[0];
    
    switch (id) {
        case 1: {
            auto value = getInt32ValueFromPacket(packet);
            Settings.setFlywheelNormalSpeed(value);
            break;
        }
        case 2: {
            auto value = getInt32ValueFromPacket(packet);
            Settings.setFlywheelMediumSpeed(value);
            break;
        }
        case 3: {
            auto value = getInt32ValueFromPacket(packet);
            Settings.setFlywheelMaxSpeed(value);
            break;
        }
        case 4: {
            auto value = getInt32ValueFromPacket(packet);
            Settings.setFeedNormalSpeed(value);
            break;
        }
        case 5: {
            auto value = getInt32ValueFromPacket(packet);
            Settings.setFeedHighSpeed(value);
            break;
        }
        case 6: {
            auto value = getInt32ValueFromPacket(packet);
            Settings.setFeedMaxSpeed(value);
            break;
        }
        case 7: {
            auto value = getFloatValueFromPacket(packet);
            Settings.setFlywheelTrimVariance(value);
            break;
        }
    }
}

int ChangeConfigurationSettingCommand::getInt32ValueFromPacket(Packet_t packet) {
    return Convert.toInt32(packet.body + 1);
}

float ChangeConfigurationSettingCommand::getFloatValueFromPacket(Packet_t packet) {
    return Convert.toFloat(packet.body + 1);
}