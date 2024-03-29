#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H

#include "Command.h"

// Provides a factory class for creating command instances.
class CommandFactory {
    public:
        // Creates a new command.
        Command* createCommand(const uint8_t type, const uint8_t subtype);
};

#endif /* COMMAND_FACTORY_H */