#ifndef NRF52_H
#define NRF52_H

#include "InterruptSignal.h"

typedef void (*ReadPacketCallback)(const uint8_t type, const uint8_t subtype, const uint8_t* data, const uint8_t len);

class NRF52 {
    public:
        NRF52(uint8_t addr, uint32_t signalPin);
        ~NRF52();
        
        void init();
        bool hasPendingPackets();

        void setCharacteristic(uint8_t characteristicId, bool value);
        void setCharacteristic(uint8_t characteristicId, uint8_t value);
        void setCharacteristic(uint8_t characteristicId, float value);
        void setCharacteristic(uint8_t characteristicId, int value);
        void setCharacteristic(uint8_t characteristicId, uint8_t *data, uint8_t len);

        void setName(const char* name);
        void setPin(const char* pin);
        
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

extern NRF52 BT;

#endif /* NRF52_H */