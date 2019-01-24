#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>
#include "GPIO/DigitalPin.h"

class Motor {
    public:
        void init(uint32_t pin);

        void start();
        void stop();

    private:
        DigitalPin* m_in1Pin;
        DigitalPin* m_in2Pin;

        bool m_started;
};

#endif