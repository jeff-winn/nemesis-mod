#ifndef BLUETOOTH_CONTROLLER_H
#define BLUETOOTH_CONTROLLER_H

#include <Adafruit_BLE.h>
#include <Adafruit_BluefruitLE_SPI.h>

// Provides a controller around the bluetooth hardware.
class BluetoothController {
    public:
        BluetoothController(Adafruit_BluefruitLE_SPI* ble);
        
        void init();
        
    private:
        Adafruit_BluefruitLE_SPI* m_ble;
};

#endif