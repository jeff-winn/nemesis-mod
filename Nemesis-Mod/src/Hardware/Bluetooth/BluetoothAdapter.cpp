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

Packet_t BluetoothAdapter::read() {
    Packet_t packet;

    if (m_ble->isConnected()) {
        auto header = readHeader();

        if (isPacketValid(header)) {
            packet.header = header;

            byte index = 0;
            byte buffer[header.len];

            while (m_ble->available()) {
                if (index >= header.len) {
                    break;
                }

                buffer[index] = m_ble->read();
                index++;
            }

            packet.body = buffer;
        }
    }

    return packet;
}

PacketHeader_t BluetoothAdapter::readHeader() {
    PacketHeader_t result;

    result.identifier = m_ble->read();
    Serial.println(result.identifier);

    result.version = m_ble->read();
    Serial.println(result.version);

    result.type = m_ble->read();
    Serial.println(result.type);

    result.len = m_ble->read();
    Serial.println(result.len);

    return result;
}

bool BluetoothAdapter::isPacketValid(PacketHeader_t header) {
    if (header.identifier != '!') {
        return false;
    }
    else if (header.type != 'A') {
        return false;
    }
    else if (header.len > 255) {
        return false;
    }

    return true;
}