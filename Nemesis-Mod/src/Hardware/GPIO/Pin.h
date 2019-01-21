#ifndef PIN_H
#define PIN_H

#include <stdint.h>

class Pin {
    public:
        Pin(uint32_t id);

        void setOutputMode();

        virtual int read();
        virtual void write(uint32_t value);

    protected:
        uint32_t m_Id;
};

#endif