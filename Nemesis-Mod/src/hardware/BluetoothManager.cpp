#include "BluetoothManager.h"

BluetoothManager::BluetoothManager(AdafruitBluefruit* ble) {
    m_ble = ble;
}

BluetoothManager::~BluetoothManager() {
    m_ble = NULL;
}

void BluetoothManager::beginInit() {
    // m_ble->begin();    
    // m_ble->factoryReset();
    // m_ble->echo(false);
    
    // m_ble->setMode(BLUEFRUIT_MODE_COMMAND);
}

void BluetoothManager::endInit() {
    // m_ble->setMode(BLUEFRUIT_MODE_DATA);
}

void BluetoothManager::setName(const char name[]) {
    // const auto COMMAND_TEXT = "AT+GAPDEVNAME=" + String(name);

    // char cmd[COMMAND_TEXT.length()];
    // COMMAND_TEXT.toCharArray(cmd, COMMAND_TEXT.length());

    // m_ble->sendCommandCheckOK(cmd);
}

Packet_t BluetoothManager::readPacket() {
    Packet_t packet;

    // if (m_ble->isConnected()) {
    //     packet.header = readHeader();

    //     byte index = 0;
    //     byte buffer[packet.header.len];

    //     while (index < packet.header.len) {
    //         buffer[index] = m_ble->read();
    //         index++;
    //     }

    //     packet.body = buffer;
    // }

    return packet;
}

PacketHeader_t BluetoothManager::readHeader() {
    PacketHeader_t result;

    // char identifier = m_ble->read();
    // if (identifier == '!') {
    //     result.version = m_ble->read();
    //     result.type = m_ble->read();
    //     result.len = m_ble->read();
    // }

    return result;
}