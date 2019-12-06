#ifndef BIT_CONVERTER_H
#define BIT_CONVERTER_H

#include <Arduino.h>

// Provides methods to do binary conversions.
class BitConverter {
    public:
        // Converts the binary array to an int32_t type.
        int32_t toInt32(const byte* address);

        // Converts the binary array to an float_t type.
        float_t toFloat(const byte* address);

        // Converts the value to a byte array.
        byte* toInt32Array(const int32_t value);

        // Converts the value to a byte array.
        byte* toFloatArray(const float_t value);
};

// Performs conversions between data types.
extern BitConverter Convert;

#endif /* BIT_CONVERTER_H */