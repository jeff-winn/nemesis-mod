#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include "GPIO/AnalogPin.h"

class Potentiometer {
    public:
        void init(uint8_t pin);
        int read();
    
    protected:
        virtual AnalogPin* createPin(uint8_t pin);

    private:
        AnalogPin* m_pin;
};

#endif