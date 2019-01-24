#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>
#include "GPIO/PwmPin.h"

class Motor {
    public:
        void init(uint8_t pin);

        void start(uint8_t dutyCycle);
        void stop();

    private:
        PwmPin* m_pin;
        uint8_t m_dutyCycle;
        bool m_started;
};

#endif