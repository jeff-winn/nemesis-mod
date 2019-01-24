#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>
#include "GPIO/DigitalPin.h"

class Motor {
    public:
        void init(uint8_t pin);

        void start();
        void stop();

    private:
        DigitalPin* m_in1Pin;
        bool m_started;
};

#endif