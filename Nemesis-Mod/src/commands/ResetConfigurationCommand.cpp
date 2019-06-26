#include "ResetConfigurationCommand.h"

void ResetConfigurationCommand::handleImpl(Packet_t packet) {
    m_config->defaultSettings();
}