#ifndef ANALOGPIN_H
#define ANALOGPIN_H

#include <stdint.h>
#include "Pin.h"

class AnalogPin : public Pin {
    public:
        AnalogPin::AnalogPin(uint32_t id);

        int read();
        void write(uint32_t value);
};

#endif