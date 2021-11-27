#include <Wire.h>

#include "src/App.h"
#include "src/Callbacks.h"

void setup() {    
    SetBluetoothCommandReceivedCallback(OnBluetoothCommandReceivedCallback);

    Wire.begin(0x01);
    Wire.onRequest(OnWireRequestReceivedCallback);

    Application.init();
}

void loop() {
    Application.runOnce();
}

// Occurs whenever a bluetooth command has been received.
void OnBluetoothCommandReceivedCallback(uint8_t type, uint8_t* data, uint16_t len, uint8_t subtype) {
    Application.onRemoteCommandReceived(type, subtype, data, len);
}

// Occurs whenever an i2c request has been received from the master device.
void OnWireRequestReceivedCallback() {
    Application.onI2cRequestReceived();
}