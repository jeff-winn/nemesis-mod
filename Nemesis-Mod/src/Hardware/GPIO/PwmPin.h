#ifndef PWM_PIN_H
#define PWM_PIN_H

#include "Pin.h"

class PwmPin : public Pin {
    public:
        PwmPin::PwmPin(uint8_t id);
        void init(uint32_t frequency);

        void write(uint8_t value);
        
    private:
        uint32_t m_frequency;
};

#endif