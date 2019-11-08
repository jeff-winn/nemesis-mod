#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include <bluefruit.h>

// Provides a controller for the on-board bluetooth module.
class BluetoothController {
    public:
        BluetoothController();

        ~BluetoothController();

        void beginInit();
        void endInit();

    private:
        BLEService _service;
        BLECharacteristic _flywheelSpeed;

        BLEDis _discoveryService;
};

void connect_callback(uint16_t conn_handle);
void disconnect_callback(uint16_t conn_handle, uint8_t reason);
void onFlywheelSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len);

#endif