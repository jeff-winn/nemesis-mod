#include "ChangeConfigurationSettingCommand.h"
#include "../BitConverter.h"

void ChangeConfigurationSettingCommand::handleImpl(Packet_t packet) {
    auto id = packet.body[0];
    auto value = getValueFromPacket(packet);
    
    switch (id) {
        case 1: {
            m_config->setFlywheelNormalSpeed(value);
            break;
        }
        case 2: {
            m_config->setFlywheelMediumSpeed(value);
            break;
        }
        case 3: {
            m_config->setFlywheelMaxSpeed(value);
            break;
        }
        case 4: {
            m_config->setFeedNormalSpeed(value);
            break;
        }
        case 5: {
            m_config->setFeedHighSpeed(value);
            break;
        }
        case 6: {
            m_config->setFeedMaxSpeed(value);
            break;
        }
    }
}

int ChangeConfigurationSettingCommand::getValueFromPacket(Packet_t packet) {
    return Convert.toInt32(packet.body + 1);
}