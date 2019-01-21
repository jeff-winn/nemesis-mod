#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>
#include "Pin.h"

class Motor {
    public:
        void init(uint32_t directionPin, uint32_t pwmPin);

        void start();
        void stop();

    private:
        Pin* m_directionPin;
        Pin* m_pwmPin;
};

#endif