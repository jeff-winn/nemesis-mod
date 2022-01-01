#include "SetTransmitCountCommand.h"
#include "../../I2cController.h"

void SetTransmitCountCommand::executeImpl(uint8_t *data, uint8_t len) {
    I2CBus.setTransmitCount(data[0]);
}