#include "src/I2cController.h"
#include "src/BLEController.h"

void setup() {
    I2CBus.init();
    I2CBus.waitForMaster(); // Pauses execution until the master device has completed startup.

    BLE.init();
    BLE.startAdvertising();
}

void loop() {
    delay(100);
}