#ifndef DEFAULT_CONFIGURATION_SETTINGS_COMMAND_H
#define DEFAULT_CONFIGURATION_SETTINGS_COMMAND_H

#include "ConfigurationCommand.h"

// Provides a command used to default the configuration settings.
class DefaultConfigurationSettingsCommand : public ConfigurationCommand {
    public:
        using ConfigurationCommand::ConfigurationCommand;

    protected:
        void handleImpl(Packet_t packet) override;
};

#endif