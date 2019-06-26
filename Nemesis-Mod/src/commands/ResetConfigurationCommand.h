#ifndef RESET_CONFIGURATION_COMMAND_H
#define RESET_CONFIGURATION_COMMAND_H

#include "ConfigurationCommand.h"

// Provides a command used to reset the configuration.
class ResetConfigurationCommand : public ConfigurationCommand {
    public:
        using ConfigurationCommand::ConfigurationCommand;

    protected:
        void handleImpl(Packet_t packet) override;
};

#endif