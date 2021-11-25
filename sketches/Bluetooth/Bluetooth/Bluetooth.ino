#include "src/BLEController.h"

void setup() {
    BLE.init();
    BLE.startAdvertising();
}

void loop() {
    delay(100);
}