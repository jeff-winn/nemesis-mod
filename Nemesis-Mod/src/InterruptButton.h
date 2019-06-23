#ifndef INTERRUPT_BUTTON_H
#define INTERRUPT_BUTTON_H

#include "InterruptPin.h"
#include "Button.h"

// Provides a button which will trigger an interrupt pin.
class InterruptButton : public Button {
    public:
        InterruptButton(InterruptPin* pin);

        ~InterruptButton();
        
        // Intializes the button.
        void init() override;

        // Returns a value indicating whether the button is pressed.
        bool isPressed() override;

    private:
        InterruptPin* m_pin;
};

#endif