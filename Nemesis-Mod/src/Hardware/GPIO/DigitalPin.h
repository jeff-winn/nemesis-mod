#ifndef DIGITAL_PIN_H
#define DIGITAL_PIN_H

#include <stdint.h>
#include "../HAL.h"
#include "Pin.h"

class DigitalPin : public Pin {
    public:
        DigitalPin::DigitalPin(uint8_t id);

        int read();
        void write(uint32_t value);
    
    private:
        HAL* hal;
};

#endif