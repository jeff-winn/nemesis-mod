#include "ChangeConfigurationSettingCommand.h"
#include "../BitConverter.h"

void ChangeConfigurationSettingCommand::handleImpl(Packet_t packet) {
    auto id = packet.body[0];
    
    switch (id) {
        case 1: {
            auto value = getInt32ValueFromPacket(packet);
            m_config->setFlywheelNormalSpeed(value);
            break;
        }
        case 2: {
            auto value = getInt32ValueFromPacket(packet);
            m_config->setFlywheelMediumSpeed(value);
            break;
        }
        case 3: {
            auto value = getInt32ValueFromPacket(packet);
            m_config->setFlywheelMaxSpeed(value);
            break;
        }
        case 4: {
            auto value = getInt32ValueFromPacket(packet);
            m_config->setFeedNormalSpeed(value);
            break;
        }
        case 5: {
            auto value = getInt32ValueFromPacket(packet);
            m_config->setFeedHighSpeed(value);
            break;
        }
        case 6: {
            auto value = getInt32ValueFromPacket(packet);
            m_config->setFeedMaxSpeed(value);
            break;
        }
        case 7: {
            auto value = getFloatValueFromPacket(packet);
            m_config->setFlywheelTrimVariance(value);
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