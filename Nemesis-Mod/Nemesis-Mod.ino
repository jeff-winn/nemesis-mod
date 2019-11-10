#include <Arduino.h>
#include "src/bluetooth/RemoteCommandReceivedCallback.h"
#include "src/bluetooth/BluetoothController.h"
#include "src/App.h"
#include "src/Log.h"

App Application = App();
BluetoothController BLE = BluetoothController();

void setup() {
    Log.waitForUsbConnection();
    Application.init();

    setupBle();
}

void setupBle() {
    SetBluetoothCommandReceivedCallback(OnBluetoothCommandReceivedCallback);
    BLE.init();
    BLE.startAdvertising();
}

// Receives notifications whenever a bluetooth command has been received. 
void OnBluetoothCommandReceivedCallback(uint8_t type, uint8_t* data, uint16_t len, uint8_t subtype) {
    Packet_t packet;
    packet.header.type = type;
    packet.header.subtype = subtype;
    packet.header.len = len;
    packet.body = data;

    Application.onRemoteCommandReceived(packet);
}

void loop() {
    Application.run();
}