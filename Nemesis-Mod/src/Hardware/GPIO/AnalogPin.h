#ifndef ANALOG_PIN_H
#define ANALOG_PIN_H

#include <stdint.h>
#include "Pin.h"

class AnalogPin : public Pin {
    public:
        AnalogPin::AnalogPin(uint8_t id);

        int read();
        void write(uint32_t value);
};

#endif