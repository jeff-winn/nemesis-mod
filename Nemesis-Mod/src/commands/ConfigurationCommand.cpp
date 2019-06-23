#include "ConfigurationCommand.h"

ConfigurationCommand::ConfigurationCommand(ConfigurationSettings* config) {
    m_config = config;
}

ConfigurationCommand::~ConfigurationCommand() {
    m_config = NULL;
}