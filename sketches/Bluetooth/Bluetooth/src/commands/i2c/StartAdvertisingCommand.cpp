#include "StartAdvertisingCommand.h"
#include "../../BLEController.h"

void StartAdvertisingCommand::executeImpl(uint8_t *data, uint8_t len) {
    BLE.startAdvertising();
}