#ifndef POLLED_BUTTON_H
#define POLLED_BUTTON_H

#include "GPIO/DigitalPin.h"
#include "Button.h"

// Provides a button which can be polled.
class PolledButton : public Button {
    public:
        PolledButton(DigitalPin* pin);

        // Initializes the button.
        virtual void init();

        // Returns a value indicating whether the button is pressed.
        virtual bool isPressed() override;

    private:
        DigitalPin* m_pin;
};

#endif