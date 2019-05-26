#ifndef BUTTON_H
#define BUTTON_H

// Represents a button.
class Button {
    public:        
        // Initializes the button.
        virtual void init() = 0;

        // Returns a value indicating whether the button is pressed.
        virtual bool isPressed();
};

#endif