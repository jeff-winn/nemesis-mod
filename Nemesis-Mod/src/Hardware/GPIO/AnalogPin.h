#ifndef ANALOG_PIN_H
#define ANALOG_PIN_H

#include "Pin.h"

namespace App { namespace Hardware { namespace GPIO
{
    class AnalogPin : public Pin {
        public:
            AnalogPin::AnalogPin(uint8_t id);

            int read();
            void write(uint32_t value);
    };
}}}

#endif