#ifndef BUTTON_H
#define BUTTON_H

#include "GPIO/InterruptPin.h"

// Provides a button which will trigger an interrupt pin.
class InterruptButton {
    public:
        InterruptButton(InterruptPin* pin);
        
        // Intializes the button with the callback specified.
        virtual void init(void (*onStateChangedCallback)(void));

        // Returns a value indicating whether the button is pressed.
        virtual bool isPressed();

    private:
        InterruptPin* m_pin;
};

#endif