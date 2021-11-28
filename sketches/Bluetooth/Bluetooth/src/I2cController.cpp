#include <Arduino.h>
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
    m_buffer = new CircularBuffer<uint8_t, 1024>();
}

I2cController::~I2cController() {
    delete m_buffer;
}

void I2cController::init() {
    Wire.onReceive(OnI2cDataReceivedCallback);
    Wire.onRequest(OnI2cRequestReceivedCallback);

    Wire.begin(NRF52840_I2C_ADDR);
}

void I2cController::onI2cDataReceived(int numBytes) {
    uint8_t *bytes = new uint8_t[numBytes];
    auto actualRead = Wire.readBytes(bytes, numBytes);
}

void I2cController::onI2cRequestReceived() {
    if (m_buffer->isEmpty()) {
        return;
    }

    auto type = m_buffer->pop();
    auto subtype = m_buffer->pop();
    auto len = m_buffer->pop();

    auto size = len + 3;

    uint8_t *packet = new uint8_t[size];
    packet[0] = type;
    packet[1] = subtype;
    packet[2] = len;

    uint8_t index = 3;
    while (index < size) {
        packet[index] = m_buffer->pop();
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