#ifndef PIN_H
#define PIN_H

#include <stdint.h>

class Pin {
    public:
        Pin(uint8_t id);

        void setOutputMode();

        virtual int read();
        virtual void write(uint32_t value);

    protected:
        uint8_t m_Id;
};

#endif