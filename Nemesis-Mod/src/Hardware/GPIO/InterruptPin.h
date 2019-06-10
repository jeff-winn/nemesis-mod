#ifndef INTERRUPT_PIN_H
#define INTERRUPT_PIN_H

#include "Pin.h"

// Represents a GPIO interrupt pin with a user defined callback function.
class InterruptPin : public Pin {
    public:
        InterruptPin(
            uint8_t id, 
            InterruptCallback onInterruptCallback, 
            InterruptMode mode, 
            Mainboard* mainboard);
        
        // Reads the value of the pin.
        virtual int read();
};

#endif