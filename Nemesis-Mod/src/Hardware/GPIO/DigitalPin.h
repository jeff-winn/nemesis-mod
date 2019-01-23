#ifndef DIGITAL_PIN_H
#define DIGITAL_PIN_H

#include <stdint.h>
#include "Pin.h"

class DigitalPin : public Pin {
    public:
        DigitalPin::DigitalPin(uint32_t id);

        int read();
        void write(uint32_t value);
};

#endif