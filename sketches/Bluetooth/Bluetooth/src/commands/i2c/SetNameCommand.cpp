#include "SetNameCommand.h"
#include "../../BLEController.h"

void SetNameCommand::executeImpl(uint8_t *data, uint8_t len) {
    char name[len];
    const char* value = (char*)data;

    strlcpy(name, value, len);

    BLE.init(name);
}