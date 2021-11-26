#include "App.h"

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