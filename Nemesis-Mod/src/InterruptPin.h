#ifndef INTERRUPT_PIN_H
#define INTERRUPT_PIN_H

#include "Pin.h"

// Represents a GPIO interrupt pin with a user defined callback function.
class InterruptPin : public Pin {
    public:
        InterruptPin(
            uint8_t id, 
            InterruptCallback callback, 
            InterruptMode mode, 
            Mainboard* mainboard);
        
        // Initializes the interrupt.
        void init();

        // Reads the value of the pin.
        virtual int read();
    
    private:
        InterruptCallback m_callback;
        InterruptMode m_mode;
};

#endif