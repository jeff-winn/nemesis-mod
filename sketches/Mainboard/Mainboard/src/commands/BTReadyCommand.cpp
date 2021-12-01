#include "BTReadyCommand.h"

#include "../ConfigurationSettings.h"
#include "../hardware/NRF52.h"

BTReadyCommand::BTReadyCommand() {    
}

BTReadyCommand::~BTReadyCommand() {
}

void BTReadyCommand::handleImpl(uint8_t* data, uint16_t len) {    
    BT.startAdvertising();
}