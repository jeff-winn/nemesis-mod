#include <stddef.h>

#include "I2cCommandFactory.h"
#include "i2c/ResetCommand.h"
#include "i2c/StartAdvertisingCommand.h"
#include "i2c/SetCharacteristicCommand.h"
#include "i2c/SetTransmitCountCommand.h"
#include "../shared/Constants.h"

I2cCommandFactory I2cCommands = I2cCommandFactory();

I2cCommandFactory::I2cCommandFactory() {    
}

I2cCommandFactory::~I2cCommandFactory() {
}

Command *I2cCommandFactory::create(uint8_t type, uint8_t subtype) {
    switch (type) {
        case NRF52_CID_START_ADVERTISING: {
            return new StartAdvertisingCommand();
        }
        case NRF52_CID_RESET: {
            return new ResetCommand();            
        }
        case NRF52_CID_SET_TRANSMIT_COUNT: {
            return new SetTransmitCountCommand();
        }
        case NRF52_CID_SET_CHARACTERISTIC: {
            return new SetCharacteristicCommand(subtype);
        }
    }

    return NULL;
}