#ifndef COMMAND_H
#define COMMAND_H

#include "bluetooth/Packet.h"

// Provides a base class for commands.
class Command {
    public:       
        virtual ~Command();

        // Indicates whether the command requires authorization to handle.
        virtual bool requiresAuthorization();

        // Handles the packet.
        void handle(Packet_t packet);

    protected:
        virtual void handleImpl(Packet_t packet);
        virtual bool validate(Packet_t packet);
};

#endif