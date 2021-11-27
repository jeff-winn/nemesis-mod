#ifndef INTERRUPT_PIN_H
#define INTERRUPT_PIN_H

#include <stdint.h>

class InterruptPin {
    public:
        InterruptPin(uint32_t pin, bool setLedOn);

        void init();

        void set();

        void reset();

    private:
        uint32_t m_pin;
        bool m_setLedOn;        
};

#endif /* INTERRUPT_PIN_H */