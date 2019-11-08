#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include <bluefruit.h>
#include "Packet.h"

// Provides a controller for the on-board bluetooth module.
class BluetoothController {
    public:
        BluetoothController();

        ~BluetoothController();

        void beginInit();
        void endInit();

        void notifyRemoteCommandReceived(Packet_t packet);

    private:
        BLEService _service;
        BLECharacteristic _flywheelSpeed;

        BLEDis _discoveryService;
};

#endif