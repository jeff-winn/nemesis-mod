#ifndef INTERRUPT_PIN_H
#define INTERRUPT_PIN_H

#include "Pin.h"

namespace App { namespace Hardware { namespace GPIO
{
    class InterruptPin : public Pin {
        public:
            InterruptPin::InterruptPin(uint8_t id, uint8_t interruptId);
            void init(void (*onStateChangedCallback)(void), InterruptMode mode);

            int read();
            
        protected:
            uint8_t m_interruptId;
    };
}}}

#endif