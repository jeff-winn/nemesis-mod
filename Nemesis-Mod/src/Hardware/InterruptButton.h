#ifndef INTERRUPT_BUTTON_H
#define INTERRUPT_BUTTON_H

#include "GPIO/InterruptPin.h"
#include "Button.h"

// Provides a button which will trigger an interrupt pin.
class InterruptButton : public Button {
    public:
        InterruptButton(InterruptPin* pin);
        
        // Intializes the button with the callback specified.
        virtual void init(void (*onStateChangedCallback)(void));

        // Returns a value indicating whether the button is pressed.
        virtual bool isPressed() override;

    private:
        InterruptPin* m_pin;
};

#endif