#ifndef PWM_PIN_H
#define PWM_PIN_H

#include "Pin.h"

// Represents a Pulse Width Modulation (PWM) pin.
class PwmPin : public Pin {
    public:
        PwmPin::PwmPin(uint8_t id, uint32_t frequency);

        // Initializes the pin.
        virtual void init();

        // Writes the value to the pin.
        virtual void write(uint8_t value);
        
    private:
        uint32_t m_frequency;
};

#endif