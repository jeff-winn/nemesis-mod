#include <Arduino.h>
#include <stddef.h>
#include <Wire.h>

#include "I2cController.h"
#include "shared/Constants.h"

I2cController I2CBus = I2cController();

void OnI2cCommandReceivedCallback(int numBytes) {
    I2CBus.onI2cCommandReceived(numBytes);
}

void OnI2cRequestReceivedCallback() {
    I2CBus.onI2cRequestReceived();
}

I2cController::I2cController() {
    m_txBuffer = new CircularBuffer<uint8_t, 512>();
    m_interrupt = new InterruptPin(A0, true);
}

I2cController::~I2cController() {
    delete m_txBuffer;
    delete m_interrupt;
}

void I2cController::init(I2cCommandReceivedCallback callback) {
    m_callback = callback;
    m_interrupt->init();

    Wire.onReceive(OnI2cCommandReceivedCallback);
    Wire.onRequest(OnI2cRequestReceivedCallback);    
    Wire.begin(NRF52840_I2C_ADDR);
}

void I2cController::clear() {    
    m_interrupt->reset();
    m_txBuffer->clear();

    m_txCount = 0;
}

void I2cController::setTransmitCount(uint8_t count) {
    m_txCount = count;
}

void I2cController::onI2cCommandReceived(int numBytes) {
    uint8_t *buffer = new uint8_t[numBytes];
    Wire.readBytes(buffer, numBytes);

    auto type = buffer[0];
    auto subtype = buffer[1];
    auto len = buffer[2];

    uint8_t *data = NULL;
    if (len > 0) {
        data = new uint8_t[len];

        uint8_t pos = 3;
        uint8_t index = 0;

        while (index < len) {
            data[index] = buffer[pos];

            index++;
            pos++;
        }
    }

    m_callback(type, subtype, data, len);

    if (data != NULL) {
        delete[] data;
    }

    delete[] buffer;
}

void I2cController::forwardPacket(uint8_t type, uint8_t subtype, uint8_t *data, uint8_t len) { 
    m_txBuffer->push(type);
    m_txBuffer->push(subtype);
    m_txBuffer->push(len);

    if (len > 0) {
        uint8_t index = 0;
        while (index < len) {
            m_txBuffer->push(data[index]);        
            index++;
        }
    }

    m_interrupt->set();
}

void I2cController::onI2cRequestReceived() {
    uint8_t *buffer = new uint8_t[m_txCount];

    uint8_t index = 0;
    while (index < m_txCount) {
        buffer[index] = m_txBuffer->shift();
        index++;
    }

    Wire.write(buffer, m_txCount);
    delete[] buffer;

    if (m_txBuffer->isEmpty()) {
        m_interrupt->reset();
    }
}