#ifndef POLLED_BUTTON_H
#define POLLED_BUTTON_H

#include "GPIO/DigitalPin.h"
#include "Button.h"

// Provides a button which is polled for state.
class PolledButton : public Button {
    public:
        PolledButton(DigitalPin* pin);

        // Intializes the button.
        void init() override;
        
        // Returns a value indicating whether the button is pressed.
        bool isPressed() override;

    private:
        DigitalPin* m_pin;
};

#endif