#ifndef PIN_H
#define PIN_H

#include <stddef.h>
#include <stdint.h>
#include "../Interop/Mainboard.h"

// Represents a GPIO pin.
class Pin {
    public:
        Pin(uint8_t id, Mainboard* hal);

        ~Pin();

        // Sets the pin for read access.
        virtual void setInputMode();

        // Sets the pin for write access.
        virtual void setOutputMode();

    protected:
        uint8_t m_Id;
        Mainboard* hardware;
};

#endif