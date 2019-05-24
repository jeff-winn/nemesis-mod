#ifndef PACKET_HEADER_H
#define PACKET_HEADER_H

#include <Arduino.h>

// Describes the header of a packet.
struct PacketHeader_t {
    char identifier = '\x00';
    byte version = 0;
    char type = '\x00';
    byte len = 0;
};

#endif