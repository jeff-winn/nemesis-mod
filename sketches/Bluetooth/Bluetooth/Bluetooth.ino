#include "src/I2cController.h"
#include "src/BLEController.h"

void setup() {
    I2CBus.init();
    I2CBus.waitForMaster(); // Pauses execution until the master device has completed startup.

    BLE.init();
    BLE.startAdvertising();

    // SetBluetoothCommandReceivedCallback(OnBluetoothCommandReceivedCallback);
}

void loop() {
    delay(100);
}

// // Occurs whenever a bluetooth command has been received.
// void OnBluetoothCommandReceivedCallback(uint8_t type, uint8_t* data, uint16_t len, uint8_t subtype) {
//     Application.onRemoteCommandReceived(type, subtype, data, len);
// }