#include "ResetConfigurationCommand.h"

ResetConfigurationCommand::ResetConfigurationCommand(ConfigurationSettings* config) {
    m_config = config;
}

ResetConfigurationCommand::~ResetConfigurationCommand() {
    m_config = NULL;
}

void ResetConfigurationCommand::handleImpl(Packet_t packet) {
    m_config->reset();
}