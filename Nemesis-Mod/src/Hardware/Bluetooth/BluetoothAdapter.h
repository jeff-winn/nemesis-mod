#ifndef BLUETOOTH_ADAPTER_H
#define BLUETOOTH_ADAPTER_H

#include <Adafruit_BLE.h>
#include <Adafruit_BluefruitLE_SPI.h>
#include "Packet.h"

// Provides an adapter to the onboard bluetooth module.
class BluetoothAdapter {
    public:
        BluetoothAdapter(Adafruit_BluefruitLE_SPI* ble);

        ~BluetoothAdapter();

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