#include "SetNameCommand.h"
#include "../../BLEController.h"

void SetNameCommand::executeImpl(const uint8_t* data, const uint8_t len) {
    char name[len];
    const char* value = (char*)data;

    strlcpy(name, value, len);

    BLE.init(name);
}