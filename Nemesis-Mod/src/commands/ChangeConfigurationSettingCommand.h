#ifndef CHANGE_CONFIGURATION_SETTING_COMMAND_H
#define CHANGE_CONFIGURATION_SETTING_COMMAND_H

#include "ConfigurationCommand.h"

// Provides a command which changes configuration settings.
class ChangeConfigurationSettingCommand : public ConfigurationCommand {
    public:
        using ConfigurationCommand::ConfigurationCommand;

    protected:
        void handleImpl(Packet_t packet) override;
        int getValueFromPacket(Packet_t packet);
};

#endif