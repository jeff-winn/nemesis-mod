#include "SetPinCommand.h"

#include "../../BLEController.h"
#include "../../shared/BitConverter.h"

void SetPinCommand::executeImpl(const uint8_t* data, const uint8_t len) {
    auto pin = Convert.toCharArray(data, len);
    if (pin != NULL) {
        BLE.setPin(pin);
    }

    delete[] pin;
}