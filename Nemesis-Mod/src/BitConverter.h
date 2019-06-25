#ifndef BIT_CONVERTER_H
#define BIT_CONVERTER_H

#include <Arduino.h>

// Provides methods to do binary conversions.
class BitConverter {
    public:
        // Converts the binary array to an int32_t type.
        int toInt32(const byte* address);

        // Converts the integer to a byte array.
        byte* toArray(const int value);
};

#endif