#ifndef COMMAND_H
#define COMMAND_H

#include <stdint.h>

// Provides a base class for commands.
class Command {
    public:
        Command() = default;
        virtual ~Command() = default;

        // Executes the command.
        void execute(const uint8_t* data, const uint8_t len);

    protected:
        virtual void executeImpl(const uint8_t* data, const uint8_t len) = 0;
        virtual bool validate();
};

#endif /* COMMAND_H */