#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#include "GPIO/AnalogPin.h"

namespace App { namespace Hardware 
{
    class Potentiometer {
        public:
            void init(uint8_t pin);
            int read();
            
        private:
            AnalogPin* m_pin;
    };
}}

#endif