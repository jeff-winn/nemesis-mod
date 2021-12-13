#ifndef I2C_COMMAND_FACTORY_H
#define I2C_COMMAND_FACTORY_H

#include "Command.h"

class I2cCommandFactory {
    public:
        I2cCommandFactory();
        ~I2cCommandFactory();

        Command* create(uint8_t type, uint8_t subtype);
};

extern I2cCommandFactory I2cCommands;

#endif /* I2C_COMMAND_FACTORY_H */