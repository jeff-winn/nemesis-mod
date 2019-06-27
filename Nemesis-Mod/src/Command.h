#ifndef COMMAND_H
#define COMMAND_H

#include "Packet.h"

// Provides a base class for commands.
class Command {
    public:       
        virtual ~Command();

        // Indicates whether the command requires the operator to have authenticated.
        virtual bool requiresAuthentication();

        // Handles the packet.
        void handle(Packet_t packet);

    protected:
        virtual void handleImpl(Packet_t packet);
        virtual bool validate(Packet_t packet);
};

#endif