#include "StartAdvertisingCommand.h"
#include "../../BLEController.h"

StartAdvertisingCommand::StartAdvertisingCommand() {    
}

StartAdvertisingCommand::~StartAdvertisingCommand() {
}

void StartAdvertisingCommand::executeImpl(uint8_t *data, uint8_t len) {
    BLE.startAdvertising();
}