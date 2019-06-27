#include "BitConverter.h"

BitConverter Convert;

union int32_bytes_t {
    byte raw[4];
    int32_t value;
};

union float_bytes_t {
    byte raw[4];
    float value;
};

int32_t BitConverter::toInt32(const byte* address) {
    int32_bytes_t r;

    for (int index = 0; index < 4; index++) {
        r.raw[index] = address[index];
    }

    return r.value;
}

byte* BitConverter::toInt32Array(const int32_t value) {
    int32_bytes_t r;
    r.value = value;

    byte* result = new byte[4];

    for (int index = 0; index < 4; index++) {
        result[index] = r.raw[index];
    };

    return result;
}

float_t BitConverter::toFloat(const byte* address) {
    float_bytes_t r;

    for (int index = 0; index < 4; index++) {
        r.raw[index] = address[index];
    }

    return r.value;
}

byte* BitConverter::toFloatArray(const float_t value) {
    float_bytes_t r;
    r.value = value;

    byte* result = new byte[4];

    for (int index = 0; index < 4; index++) {
        result[index] = r.raw[index];
    };

    return result;
}