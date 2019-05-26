#ifndef COMMAND_H
#define COMMAND_H

#include "../Hardware/Bluetooth/Packet.h"

// Provides a base class for commands.
class Command {
    public:
        // Handles the packet.
        virtual void handle(Packet_t packet) = 0;
};

#endif