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

    auto header = readHeader();

    if (isPacketValid(header)) {
        packet.header = header;

        byte index = 0;
        byte buffer[header.len];

        while (index < header.len) {
            buffer[index] = m_ble->read();
            index++;
        }

        packet.body = buffer;
    }

    return packet;
}

PacketHeader_t BluetoothAdapter::readHeader() {
    PacketHeader_t result;

    char identifier = '\x00';
    do {
        identifier = m_ble->read();
    }
    while (identifier != '!');

    result.version = m_ble->read();
    result.type = m_ble->read();
    result.len = m_ble->read();

    return result;
}

bool BluetoothAdapter::isPacketValid(PacketHeader_t header) {
    if (header.version != '1') {
        return false;
    }
    else if (header.type != 'A') {
        return false;
    }

    return true;
}