#include "NotifyReadyCommand.h"
#include "../../I2cController.h"

NotifyReadyCommand::NotifyReadyCommand() {    
}

NotifyReadyCommand::~NotifyReadyCommand() {
}

void NotifyReadyCommand::executeImpl(uint8_t *data, uint8_t len) {
    I2CBus.notifyReady();
}