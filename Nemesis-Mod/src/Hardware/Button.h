#ifndef BUTTON_H
#define BUTTON_H

#include "GPIO/InterruptPin.h"

class Button {
    public:
        void init(uint8_t pin, uint8_t intPin, void (*onStateChangedCallback)(void));
        bool isPressed();
        
    protected:
        virtual InterruptPin* createPin(uint8_t pin, uint8_t intPin, void (*onStateChangedCallback)(void));
    
    private:
        InterruptPin* m_pin;
};

#endif