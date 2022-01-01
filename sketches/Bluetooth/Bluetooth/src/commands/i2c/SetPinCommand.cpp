#include "SetPinCommand.h"

#include "../../BLEController.h"
#include "../../shared/BitConverter.h"

void SetPinCommand::executeImpl(uint8_t *data, uint8_t len) {
    auto pin = Convert.toCharArray(data, len);
    if (pin != NULL) {
        BLE.setPin(pin);
    }

    delete[] pin;
}