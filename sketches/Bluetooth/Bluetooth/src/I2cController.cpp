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
    m_rxBuffer = new CircularBuffer<uint8_t, 512>();
    m_txBuffer = new CircularBuffer<uint8_t, 512>();

    m_interrupt = new InterruptPin(A0);
    m_led = new Led();
}

I2cController::~I2cController() {
    delete m_rxBuffer;
    delete m_txBuffer;
    delete m_led;

    delete m_interrupt;
}

void I2cController::init(I2cCommandReceivedCallback callback) {
    m_callback = callback;
    m_interrupt->init();
    m_led->init();
    
    clear();
    
    Wire.onReceive(OnI2cCommandReceivedCallback);
    Wire.onRequest(OnI2cRequestReceivedCallback);    
    Wire.begin(NRF52840_I2C_ADDR);
}

void I2cController::clear() {
    m_interrupt->reset();
    m_led->off();

    m_rxBuffer->clear();
    m_rxPending = 0;

    m_txBuffer->clear();
    m_txCount = 0;
}

void I2cController::notifyReady() {
    sendPacket(NRF52_CID_READY, 0, NULL, 0);
}

void I2cController::checkForAsyncCommands() {
    if (m_rxPending == 0) {
        return;        
    }

    auto type = m_rxBuffer->shift();
    auto subtype = m_rxBuffer->shift();
    auto len = m_rxBuffer->shift();

    uint8_t *data = NULL;
    if (len > 0) {
        data = new uint8_t[len];

        uint8_t index = 0;
        while (index < len) {
            data[index] = m_rxBuffer->shift();
            index++;
        }
    }

    m_callback(type, subtype, data, len);

    decrementPending();

    if (!shouldLedBeOn()){
        m_led->off();
    }
    
    delete[] data;
}

void I2cController::incrementPending() {
    auto pending = m_rxPending;
    pending++;

    m_rxPending = pending;
}

void I2cController::decrementPending() {
    auto pending = m_rxPending;
    pending--;

    m_rxPending = pending;
}

void I2cController::setTransmitCount(uint8_t count) {
    m_txCount = count;
}

void I2cController::onI2cCommandReceived(int numBytes) {
    uint8_t *buffer = new uint8_t[numBytes];
    Wire.readBytes(buffer, numBytes);

    auto type = buffer[0];
    auto subtype = buffer[1];

    if (shouldExecuteImmediately(type, subtype)) {
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
    }
    else {
        uint8_t index = 0;
        while (index < numBytes) {
            m_rxBuffer->push(buffer[index]);
            index++;            
        }

        incrementPending();

        if (shouldLedBeOn()) {
            m_led->on();
        }
    }

    delete[] buffer;
}

bool I2cController::shouldExecuteImmediately(uint8_t type, uint8_t subtype) {
    return type == NRF52_CID_SET_TRANSMIT_COUNT;
}

void I2cController::sendPacket(const uint8_t type, const uint8_t subtype, const uint8_t* data, const uint8_t len) { 
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

    if (shouldLedBeOn()) {
        m_led->on();
    }
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

    if (!shouldInterruptBeSet()) {
        m_interrupt->reset();
        
        if (!shouldLedBeOn()) {
            m_led->off();
        }
    }    
}

bool I2cController::shouldInterruptBeSet() {
    return !m_txBuffer->isEmpty();    
}

bool I2cController::shouldLedBeOn() {
    return !m_txBuffer->isEmpty() || !m_rxBuffer->isEmpty();
}