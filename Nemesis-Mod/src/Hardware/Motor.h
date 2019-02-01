#ifndef MOTOR_H
#define MOTOR_H

#include "GPIO/PwmPin.h"

namespace App { namespace Hardware 
{
    class Motor {
        public:
            void init(uint8_t pin, uint32_t frequency);

            void start(uint8_t dutyCycle);
            void stop();

        private:
            PwmPin* m_pin;
            uint8_t m_dutyCycle;
            bool m_started;
    };
}}

#endif