#include <Arduino.h>
#include <Wire.h>
#include "../shared/Constants.h"
#include "NRF52.h"

NRF52::NRF52(uint8_t addr) {
    m_addr = addr;
}

NRF52::~NRF52() {    
}

void NRF52::init() {
}

void NRF52::clearBonds() {
    sendPacket(NRF52_CID_CLEAR_BONDS, 0, NULL, 0);
}

void NRF52::startAdvertising() {
    uint8_t success = 0;
    do
    {
        success = sendPacket(NRF52_CID_START_ADVERTISING, 0, NULL, 0);
        if (success != 0) {
            delay(1);
        }
    } while (success != 0);    
}

uint8_t NRF52::sendPacket(uint8_t type, uint8_t subtype, uint8_t *data, uint8_t len) {
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

    auto result = Wire.endTransmission();
    delete packet;

    return result;
}