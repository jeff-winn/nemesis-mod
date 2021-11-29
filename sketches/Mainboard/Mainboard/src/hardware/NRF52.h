#ifndef NRF52_H
#define NRF52_H

#include "InterruptSignal.h"

class NRF52 {
    public:
        NRF52(uint8_t addr, uint32_t interruptPin);
        ~NRF52();
        
        void init();

        void startAdvertising();

        void reset();
    
    private:
        InterruptSignal *m_signal;
        uint8_t m_addr;
        uint8_t sendPacket(uint8_t type, uint8_t subtype, uint8_t *data, uint8_t len);
};

#endif /* NRF52_H */