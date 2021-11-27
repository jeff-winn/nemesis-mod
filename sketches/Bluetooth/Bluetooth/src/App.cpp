#include "App.h"
#include "Callbacks.h"

App Application = App();

App::App() {
    ble = new BLEController();
    interrupt = new InterruptPin(13, true);
}

void App::init() {
    ble->init();
    ble->startAdvertising();

    interrupt->init();
}

void App::runOnce() {   
    interrupt->set();

    delay(1000);

    interrupt->reset();

    delay(1000);
}

void App::onRemoteCommandReceived(uint8_t type, uint8_t subtype, uint8_t* data, uint16_t len) {
}