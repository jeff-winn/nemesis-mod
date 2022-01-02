#include "SetNameCommand.h"
#include "../../BLEController.h"

void SetNameCommand::executeImpl(const uint8_t* data, const uint8_t len) {
    String name(reinterpret_cast<const char*>(data));
   
    BLE.init(name.c_str());
}