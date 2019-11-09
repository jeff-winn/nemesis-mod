#include <Arduino.h>
#include "src/bluetooth/RemoteCommandReceivedCallback.h"
#include "src/App.h"
#include "src/Log.h"

App Application = App();

void setup() {
    Log.waitForUsbConnection();

    SetBluetoothCommandReceivedCallback(OnBluetoothCommandReceivedCallback);
    Application.init();
}

void loop() {
    Application.run();
}

// Receives notifications whenever a bluetooth command has been received. 
void OnBluetoothCommandReceivedCallback(uint8_t type, uint8_t* data, uint16_t len) {
    Packet_t packet;
    packet.header.type = type;
    packet.header.len = len;
    packet.body = data;

    Application.onRemoteCommandReceived(packet);
}