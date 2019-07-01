#ifndef CONFIGURATION_COMMAND_H
#define CONFIGURATION_COMMAND_H

#include "../Command.h"
#include "../ConfigurationSettings.h"

// Provides a base class for handling configuration commands.
class ConfigurationCommand : public Command {
    public:
        ConfigurationCommand(ConfigurationSettings* config);
        
        ~ConfigurationCommand() override;

    protected:
        ConfigurationSettings* m_config;
};

#endif