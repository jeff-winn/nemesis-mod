#include "ResetCommand.h"
#include "../../BLEController.h"

ResetCommand::ResetCommand() {    
}

ResetCommand::~ResetCommand() {
}

void ResetCommand::executeImpl(uint8_t *data, uint8_t len) {
    BLE.clearBonds();    
}