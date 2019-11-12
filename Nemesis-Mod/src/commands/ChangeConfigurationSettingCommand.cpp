#include "../BitConverter.h"
#include "../Log.h"
#include "ChangeConfigurationSettingCommand.h"

ChangeConfigurationSettingCommand::ChangeConfigurationSettingCommand() : ConfigurationCommand() {
}

void ChangeConfigurationSettingCommand::handleImpl(Packet_t packet) { 
    switch (packet.header.subtype) {
        case 1: {
            auto value = getInt32ValueFromPacket(packet);
            Settings.setFlywheelNormalSpeed(value);

            Log.println(value);
            Log.println("Changed flywheel normal speed.");
            break;
        }
        case 2: {
            auto value = getInt32ValueFromPacket(packet);
            Settings.setFlywheelMediumSpeed(value);

            Log.println("Changed flywheel medium speed.");
            break;
        }
        case 3: {
            auto value = getInt32ValueFromPacket(packet);
            Settings.setFlywheelMaxSpeed(value);

            Log.println("Changed flywheel max speed.");
            break;
        }
        case 4: {
            auto value = getInt32ValueFromPacket(packet);
            Settings.setFeedNormalSpeed(value);

            Log.println("Changed feed normal speed.");
            break;
        }
        case 5: {
            auto value = getInt32ValueFromPacket(packet);
            Settings.setFeedHighSpeed(value);

            Log.println("Changed feed high speed.");
            break;
        }
        case 6: {
            auto value = getInt32ValueFromPacket(packet);
            Settings.setFeedMaxSpeed(value);

            Log.println("Changed feed max speed.");
            break;
        }
        case 7: {
            auto value = getFloatValueFromPacket(packet);
            Settings.setFlywheelTrimVariance(value);

            Log.println(value);
            Log.println("Changed flywheel trim variance.");
            break;
        }
    }
}

int ChangeConfigurationSettingCommand::getInt32ValueFromPacket(Packet_t packet) {
    return Convert.toInt32(packet.body);
}

float ChangeConfigurationSettingCommand::getFloatValueFromPacket(Packet_t packet) {
    return Convert.toFloat(packet.body);
}