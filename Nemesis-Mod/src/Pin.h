#ifndef PIN_H
#define PIN_H

#include <stddef.h>
#include "hardware/Mainboard.h"

// Represents a GPIO pin.
class Pin {
    public:
        Pin(uint32_t id, Mainboard* hal);

        ~Pin();

        // Sets the pin for read access.
        virtual void setInputMode();

        // Sets the pin for write access.
        virtual void setOutputMode();

    protected:
        int m_Id;
        Mainboard* hardware;
};

#endif