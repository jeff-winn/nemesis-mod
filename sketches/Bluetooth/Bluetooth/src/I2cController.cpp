#include <Arduino.h>
#include <cstddef>
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
    m_rxBuffer = new CircularBuffer<uint8_t, 512>();
    m_txBuffer = new CircularBuffer<uint8_t, 512>();

    m_interrupt = new InterruptPin(A0, true);
}

I2cController::~I2cController() {
    delete m_rxBuffer;
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
    m_rxBuffer->clear();

    m_rxCount = 0;
    m_txCount = 0;
}

void I2cController::onI2cCommandReceived(int numBytes) {
    uint8_t *buffer = new uint8_t[numBytes];
    Wire.readBytes(buffer, numBytes);

    uint8_t current = 0;
    int index = 0;

    while (index < numBytes) {
        current = buffer[index];
        m_rxBuffer->push(current);

        index++;
    }

    m_rxCount++;    
    delete buffer;
}

void I2cController::runNextPacket() {
    if (m_rxCount == 0) {
        return;
    }

    auto type = m_rxBuffer->shift();
    auto subtype = m_rxBuffer->shift();
    auto len = m_rxBuffer->shift();

    byte *data = NULL;
    if (len > 0) {
        data = new byte[len];

        uint8_t index = 0;
        while (index < len) {
            data[index] = m_rxBuffer->shift();
            index++;
        }
    }

    m_callback(type, subtype, data, len);
    m_rxCount--;
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
    if (m_txCount == 0) {
        return;
    }

    auto type = m_txBuffer->shift();
    auto subtype = m_txBuffer->shift();
    auto len = m_txBuffer->shift();

    auto size = len + 3;

    uint8_t *packet = new uint8_t[size];
    packet[0] = type;
    packet[1] = subtype;
    packet[2] = len;

    uint8_t index = 3;
    while (index < size) {
        packet[index] = m_txBuffer->shift();
        index++;
    }

    Wire.write(packet, size);    
    delete packet;

    m_txCount--;

    if (m_txCount == 0) {
        m_interrupt->reset();
    }
}