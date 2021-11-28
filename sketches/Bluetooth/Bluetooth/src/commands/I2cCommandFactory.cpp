#include <cstddef>

#include "I2cCommandFactory.h"
#include "i2c/ClearBondsCommand.h"
#include "i2c/NotifyReadyCommand.h"

I2cCommandFactory I2cCommands = I2cCommandFactory();

I2cCommandFactory::I2cCommandFactory() {    
}

I2cCommandFactory::~I2cCommandFactory() {
}

Command *I2cCommandFactory::create(uint8_t type, uint8_t subtype) {
    switch (type) {
        case 0x01:
            return new NotifyReadyCommand();

        case 0x02:
            return new ClearBondsCommand();            
    }

    return NULL;
}