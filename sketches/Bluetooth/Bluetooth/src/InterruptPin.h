#ifndef INTERRUPT_PIN_H
#define INTERRUPT_PIN_H

#include <stdint.h>

class InterruptPin {
    public:
        InterruptPin(uint32_t pin);
        ~InterruptPin();
        
        void init();
        void set();
        void reset();

    private:
        uint32_t m_pin;
};

#endif /* INTERRUPT_PIN_H */