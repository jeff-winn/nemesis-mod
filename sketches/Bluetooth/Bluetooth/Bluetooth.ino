#include "src/App.h"
#include "src/Callbacks.h"

void setup() {    
    SetBluetoothCommandReceivedCallback(OnBluetoothCommandReceivedCallback);

    Application.init();
}

void loop() {
    Application.runOnce();
}

// Receives notifications whenever a bluetooth command has been received. 
void OnBluetoothCommandReceivedCallback(uint8_t type, uint8_t* data, uint16_t len, uint8_t subtype) {
    Application.onRemoteCommandReceived(type, subtype, data, len);
}