#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include <bluefruit.h>
#include "../Packet.h"

extern uint8_t UUID128_SVC_NERF_BLASTER[16];

// Provides an adapter to the onboard bluetooth module.
class BluetoothManager {
    public:
        BluetoothManager(AdafruitBluefruit* driver, BLEService* nerfDeviceService, BLEDis* deviceInformationService);

        ~BluetoothManager();

        void setName(const char name[]);

        void beginInit();
        void endInit();
        
        Packet_t readPacket();

    protected:
        PacketHeader_t readHeader();

    private:
        AdafruitBluefruit* m_driver;
        BLEService* m_nerfDeviceService;
        BLEDis* m_deviceInformationService;
};

#endif