#include "ClearBondsCommand.h"
#include "../../BLEController.h"

ClearBondsCommand::ClearBondsCommand() {    
}

ClearBondsCommand::~ClearBondsCommand() {
}

void ClearBondsCommand::executeImpl(uint8_t *data, uint8_t len) {
    BLE.clearBonds();    
}