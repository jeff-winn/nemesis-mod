#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include <bluefruit.h>
#include "../Packet.h"

// Provides an adapter to the onboard bluetooth module.
class BluetoothManager {
    public:
        BluetoothManager(AdafruitBluefruit* ble);

        ~BluetoothManager();

        void setName(const char name[]);

        void beginInit();
        void endInit();
        
        Packet_t readPacket();

    protected:
        PacketHeader_t readHeader();
        
    private:
        AdafruitBluefruit* m_ble;
};

#endif