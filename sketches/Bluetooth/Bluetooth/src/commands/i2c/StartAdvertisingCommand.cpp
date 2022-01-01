#include "StartAdvertisingCommand.h"
#include "../../BLEController.h"

void StartAdvertisingCommand::executeImpl(const uint8_t* data, const uint8_t len) {
    BLE.startAdvertising();
}