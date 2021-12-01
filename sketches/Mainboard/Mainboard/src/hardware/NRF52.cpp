#include <Arduino.h>
#include <Wire.h>
#include "../shared/Constants.h"
#include "../shared/BitConverter.h"
#include "NRF52.h"

NRF52 BT = NRF52(NRF52840_I2C_ADDR, A0);

NRF52::NRF52(uint8_t addr, uint32_t signalPin) {    
    m_addr = addr;
    m_signal = new InterruptSignal(signalPin);
}

NRF52::~NRF52() {
    delete m_signal;
}

void NRF52::init() {
    m_signal->init();
}

void NRF52::reset() {
    sendPacket(NRF52_CID_RESET, 0, NULL, 0);
}

bool NRF52::hasPendingPackets() {
    return m_signal->isSet();
}

void NRF52::startAdvertising() {
    sendPacket(NRF52_CID_START_ADVERTISING, 0, NULL, 0);    
}

void NRF52::setCharacteristic(uint8_t characteristicId, uint8_t value) {
    setCharacteristic(characteristicId, &value, 1);
}

void NRF52::setCharacteristic(uint8_t characteristicId, float value) {
    auto data = Convert.toFloatArray(value);
    setCharacteristic(characteristicId, data, 4);

    delete[] data;
}

void NRF52::setCharacteristic(uint8_t characteristicId, uint32_t value) {
    auto data = Convert.toInt32Array(value);
    setCharacteristic(characteristicId, data, 4);

    delete[] data;    
}

void NRF52::setCharacteristic(uint8_t characteristicId, uint8_t *data, uint8_t len) {
    sendPacket(NRF52_CID_SET_CHARACTERISTIC, characteristicId, data, len);
}

void NRF52::readPacket(ReadPacketCallback callback) {
    setTransmitCount(3);

    uint8_t *header = new uint8_t[3];
    Wire.requestFrom(m_addr, 3);
    Wire.readBytes(header, 3);
    
    auto type = header[0];
    auto subtype = header[1];
    auto len = header[2];

    uint8_t *data = NULL;
    if (len > 0) {
        setTransmitCount(len);

        data = new uint8_t[len];
        Wire.requestFrom(m_addr, len);
        Wire.readBytes(data, len);
    }

    callback(type, subtype, data, len);
}

void NRF52::setTransmitCount(uint8_t count) {
    Wire.beginTransmission(m_addr);
    Wire.write(NRF52_CID_SET_TRANSMIT_COUNT);
    Wire.write((uint8_t)0);
    Wire.write((uint8_t)1);
    Wire.write(count);
    Wire.endTransmission();
}

void NRF52::sendPacket(uint8_t type, uint8_t subtype, uint8_t *data, uint8_t len) {
    size_t size = len + 3;

    uint8_t *packet = new uint8_t[size];
    packet[0] = type;
    packet[1] = subtype;
    packet[2] = len;

    if (len > 0) {
        uint8_t index = 0;
        uint8_t pos = 3;

        while (index < len) {
            packet[pos] = data[index];
        }
    }    

    Wire.beginTransmission(m_addr);
    Wire.write(packet, size);
    Wire.endTransmission();
    
    delete packet;
}