#include <Wire.h>

#include "App.h"
#include "Callbacks.h"

App Application = App();
BLEController ble = BLEController();
InterruptPin interruptPin = InterruptPin(A0, true);

App::App() {
    txBuffer = new CircularBuffer<uint8_t, 1024>();
}

void App::init() {   
    ble.init();
    ble.startAdvertising();

    interruptPin.init();
}

void App::runOnce() {
    delay(100);
}

void App::onI2cRequestReceived() {
    auto type = txBuffer->pop();
    auto subtype = txBuffer->pop();
    auto len = txBuffer->pop();

    uint8_t size = len + 3;

    byte *packet = new byte[size];
    packet[0] = type;
    packet[1] = subtype;
    packet[2] = len;

    uint8_t index = 3;
    while (index < len) {
        packet[index] = txBuffer->pop();
        index++;
    }

    Wire.write(packet, size);

    if (txBuffer->isEmpty()) {
        interruptPin.reset();
    }
}

void App::onRemoteCommandReceived(uint8_t type, uint8_t subtype, uint8_t* data, uint8_t len) {
    txBuffer->push(type);
    txBuffer->push(subtype);
    txBuffer->push(len);

    uint8_t index = 0;
    while (index < len) {
        txBuffer->push(data[index]);
        index++;
    }

    interruptPin.set();
}