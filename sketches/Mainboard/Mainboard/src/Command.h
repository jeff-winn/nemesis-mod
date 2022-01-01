#ifndef COMMAND_H
#define COMMAND_H

#include <stdint.h>

// Provides a base class for commands.
class Command {
    public:       
        virtual ~Command() = default;

        // Indicates whether the command requires authorization to handle.
        virtual bool requiresAuthorization();

        // Handles the packet.
        void handle(const uint8_t* data, const uint16_t len);

    protected:
        virtual void handleImpl(const uint8_t* data, const uint16_t len);
        virtual bool validate(const uint8_t* data, const uint16_t len);
};

#endif /* COMMAND_H */