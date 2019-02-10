#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include "GPIO/AnalogPin.h"

// Represents a potentiometer.
class Potentiometer {
    public:
        Potentiometer::Potentiometer(AnalogPin* pin);

        // Reads the value.
        virtual float read();

    private:
        AnalogPin* m_pin;
};

#endif