#ifndef BUTTON_H
#define BUTTON_H

#include "GPIO/DigitalPin.h"

class Button {
    public:
        void init(uint8_t pin);
        bool isPressed();

    protected:
        DigitalPin* m_pin;
};

#endif