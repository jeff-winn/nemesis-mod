#ifndef DIGITAL_PIN_H
#define DIGITAL_PIN_H

#include "Pin.h"

// Represents a GPIO digital pin.
class DigitalPin : public Pin {
    public:
        DigitalPin::DigitalPin(uint8_t id);

        // Reads the value of the pin.
        virtual int read();
        
        // Writes the value to the pin.
        virtual void write(uint32_t value);
};

#endif