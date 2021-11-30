#ifndef NRF52_H
#define NRF52_H

#include "InterruptSignal.h"

typedef void (*ReadPacketCallback)(uint8_t type, uint8_t subtype, uint8_t *data, uint8_t len);

class NRF52 {
    public:
        NRF52(uint8_t addr, uint32_t signalPin);
        ~NRF52();
        
        void init();
        bool hasPendingPackets();

        void startAdvertising();

        void readPacket(ReadPacketCallback callback);
        void reset();

    protected:
        void setTransmitCount(uint8_t count);
        void sendPacket(uint8_t type, uint8_t subtype, uint8_t *data, uint8_t len);
    
    private:
        InterruptSignal *m_signal;
        uint8_t m_addr;
};

#endif /* NRF52_H */