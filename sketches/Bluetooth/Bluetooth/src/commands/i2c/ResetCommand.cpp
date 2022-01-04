#include "ResetCommand.h"
#include "../../BLEController.h"

void ResetCommand::executeImpl(const uint8_t* data, const uint8_t len) {
    BLE.clearBonds();    
}