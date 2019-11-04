#include "DefaultConfigurationSettingsCommand.h"

void DefaultConfigurationSettingsCommand::handleImpl(Packet_t packet) {
    Settings.defaultSettings();
}