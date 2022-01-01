#include "SetTransmitCountCommand.h"
#include "../../I2cController.h"

void SetTransmitCountCommand::executeImpl(const uint8_t* data, const uint8_t len) {
    I2CBus.setTransmitCount(data[0]);
}