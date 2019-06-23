#ifndef RESET_CONFIGURATION_COMMAND_H
#define RESET_CONFIGURATION_COMMAND_H

#include "../Command.h"
#include "../ConfigurationSettings.h"

class ResetConfigurationCommand : public Command {
    public:
        ResetConfigurationCommand(ConfigurationSettings* config);

        ~ResetConfigurationCommand() override;

    protected:
        void handleImpl(Packet_t packet) override;
        
    private:
        ConfigurationSettings* m_config;
};

#endif