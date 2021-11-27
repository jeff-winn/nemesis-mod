#include "App.h"
#include "Callbacks.h"

App Application = App();
BLEController ble = BLEController();
InterruptPin interruptPin = InterruptPin(13, true);

App::App() {    
}

void App::init() {
    ble.init();
    ble.startAdvertising();

    interruptPin.init();
}

void App::runOnce() {   
    interruptPin.set();

    delay(1000);

    interruptPin.reset();

    delay(1000);
}

void App::onRemoteCommandReceived(uint8_t type, uint8_t subtype, uint8_t* data, uint16_t len) {
}