#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include <bluefruit.h>
#include "../Packet.h"

extern uint8_t UUID128_SVC_NERF_BLASTER[16];

// Provides an adapter to the onboard bluetooth module.
class BluetoothManager {
    public:
        BluetoothManager();

        ~BluetoothManager();

        void beginInit();
        void endInit();
        
        Packet_t readPacket();

    protected:
        PacketHeader_t readHeader();

    private:
};

#endif