#include <Arduino.h>
#include <cstddef>
#include <Wire.h>
#include "I2cController.h"
#include "shared/Constants.h"

I2cController I2CBus = I2cController();

void OnI2cDataReceivedCallback(int numBytes) {
    I2CBus.onI2cDataReceived(numBytes);
}

void OnI2cRequestReceivedCallback() {
    I2CBus.onI2cRequestReceived();
}

I2cController::I2cController() {
    m_txBuffer = new CircularBuffer<uint8_t, 512>();
}

I2cController::~I2cController() {
    delete m_txBuffer;
}

void I2cController::init(I2cCommandReceivedCallback callback) {
    m_callback = callback;

    Wire.onReceive(OnI2cDataReceivedCallback);
    Wire.onRequest(OnI2cRequestReceivedCallback);
    Wire.begin(NRF52840_I2C_ADDR);
}

void I2cController::onI2cDataReceived(int numBytes) {
    uint8_t *buffer = new uint8_t[numBytes];
    Wire.readBytes(buffer, numBytes);

    auto type = buffer[0];
    auto subtype = buffer[1];
    auto len = buffer[2];

    uint8_t *data = NULL;
    if (len > 0) {    
        uint8_t pos = 3;
        uint8_t index = 0;

        data = new uint8_t[len];
        while (pos < numBytes) {
            data[index] = buffer[pos];

            index++;
            pos++;
        }
    }
    
    m_callback(type, subtype, data, len);
    if (data != NULL) {
        delete data;
    }

    delete buffer;
}

void I2cController::onI2cRequestReceived() {
    if (m_txBuffer->isEmpty()) {
        return;
    }

    auto type = m_txBuffer->pop();
    auto subtype = m_txBuffer->pop();
    auto len = m_txBuffer->pop();

    auto size = len + 3;

    uint8_t *packet = new uint8_t[size];
    packet[0] = type;
    packet[1] = subtype;
    packet[2] = len;

    uint8_t index = 3;
    while (index < size) {
        packet[index] = m_txBuffer->pop();
        index++;
    }

    Wire.write(packet, size);    
    delete packet;
}

void I2cController::notifyReady() {
    m_ready = true;
}

void I2cController::waitForMaster() {
    while (!m_ready) {
        delay(1);
    }
}