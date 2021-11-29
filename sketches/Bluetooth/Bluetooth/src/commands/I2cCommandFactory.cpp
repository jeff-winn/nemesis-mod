#include <cstddef>

#include "I2cCommandFactory.h"
#include "i2c/ClearBondsCommand.h"
#include "i2c/StartAdvertisingCommand.h"
#include "../shared/Constants.h"

I2cCommandFactory I2cCommands = I2cCommandFactory();

I2cCommandFactory::I2cCommandFactory() {    
}

I2cCommandFactory::~I2cCommandFactory() {
}

Command *I2cCommandFactory::create(uint8_t type, uint8_t subtype) {
    switch (type) {
        case NRF52_CID_START_ADVERTISING:
            return new StartAdvertisingCommand();

        case NRF52_CID_CLEAR_BONDS:
            return new ClearBondsCommand();            
    }

    return NULL;
}