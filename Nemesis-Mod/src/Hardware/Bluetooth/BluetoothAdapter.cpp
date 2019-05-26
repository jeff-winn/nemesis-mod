#include "BluetoothAdapter.h"

BluetoothAdapter::BluetoothAdapter(Adafruit_BluefruitLE_SPI* ble) {
    m_ble = ble;
}

void BluetoothAdapter::beginInit() {
    m_ble->begin();    
    m_ble->factoryReset();
    m_ble->echo(false);
    
    m_ble->setMode(BLUEFRUIT_MODE_COMMAND);
}

void BluetoothAdapter::endInit() {
    m_ble->setMode(BLUEFRUIT_MODE_DATA);
}

void BluetoothAdapter::setName(const char name[]) {
    const auto COMMAND_TEXT = "AT+GAPDEVNAME=" + String(name);

    char cmd[COMMAND_TEXT.length()];
    COMMAND_TEXT.toCharArray(cmd, COMMAND_TEXT.length());

    m_ble->sendCommandCheckOK(cmd);
}

Packet_t BluetoothAdapter::readPacket() {
    Packet_t packet;

    if (m_ble->isConnected()) {
        Serial.println("reading packet...");
        packet.header = readHeader();

        byte index = 0;
        byte buffer[packet.header.len];

        while (index < packet.header.len) {
            buffer[index] = m_ble->read();
            index++;
        }

        packet.body = buffer;
    }

    return packet;
}

PacketHeader_t BluetoothAdapter::readHeader() {
    PacketHeader_t result;

    char identifier = m_ble->read();
    if (identifier == '!') {
        result.version = m_ble->read();
        Serial.println(result.version);

        result.type = m_ble->read();
        Serial.println(result.type);

        result.len = m_ble->read();
        Serial.println(result.len);
    }

    return result;
}