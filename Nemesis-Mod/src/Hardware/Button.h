#ifndef BUTTON_H
#define BUTTON_H

#include "GPIO/InterruptPin.h"

class Button {
    public:
        Button(InterruptPin* pin);

        virtual void init(void (*onStateChangedCallback)(void));
        virtual bool isPressed();

    private:
        InterruptPin* m_pin;
};

#endif