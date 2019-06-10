#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include <Adafruit_BLE.h>
#include <Adafruit_BluefruitLE_SPI.h>
#include "../Packet.h"

// Provides an adapter to the onboard bluetooth module.
class BluetoothManager {
    public:
        BluetoothManager(Adafruit_BluefruitLE_SPI* ble);

        ~BluetoothManager();

        void setName(const char name[]);

        void beginInit();
        void endInit();
        
        Packet_t readPacket();

    protected:
        PacketHeader_t readHeader();
        
    private:
        Adafruit_BluefruitLE_SPI* m_ble;
};

#endif