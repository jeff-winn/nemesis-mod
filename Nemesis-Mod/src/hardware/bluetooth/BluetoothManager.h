#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include <bluefruit.h>
#include "CustomUuid.h"
#include "CustomCharacteristics.h"
#include "CustomServices.h"
#include "../../Packet.h"

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