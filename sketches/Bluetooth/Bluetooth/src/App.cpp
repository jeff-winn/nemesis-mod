#include "App.h"
#include "Callbacks.h"

App Application = App();

App::App() {
    ble = BLEController();
}

void App::init() {

    ble.init();
    ble.startAdvertising();
}

void App::runOnce() {
    delay(100);
}

void App::onRemoteCommandReceived(uint8_t type, uint8_t subtype, uint8_t* data, uint16_t len) {
}