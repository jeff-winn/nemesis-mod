#ifndef PACKET_HEADER_H
#define PACKET_HEADER_H

#include <Arduino.h>

// Describes the header of a packet.
struct PacketHeader_t {
    byte type = 0;
    byte len = 0;
};

#endif