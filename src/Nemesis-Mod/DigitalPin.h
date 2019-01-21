#ifndef DIGITALPIN_H
#define DIGITALPIN_H

#include <stdint.h>
#include "Pin.h"

class DigitalPin : public Pin {
    public:
        DigitalPin::DigitalPin(uint32_t id);
        void write(uint32_t value);
};

#endif