#ifndef PACKET_H
#define PACKET_H

#include "PacketHeader.h"

// Describes a packet.
struct Packet_t {
    PacketHeader_t header;
    byte* body;
};

#endif