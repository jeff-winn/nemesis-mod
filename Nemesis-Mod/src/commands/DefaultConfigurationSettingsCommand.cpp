#include "DefaultConfigurationSettingsCommand.h"

void DefaultConfigurationSettingsCommand::handleImpl(Packet_t packet) {
    m_config->defaultSettings();
}