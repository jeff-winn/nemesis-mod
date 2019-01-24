#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>
#include "GPIO/Pin.h"

class Button {
    public:
        void init(uint8_t pin);
        bool isPressed();

    protected:
        Pin* m_pin;
};

#endif