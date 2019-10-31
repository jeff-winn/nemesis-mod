#include "BluetoothManager.h"

uint8_t UUID128_SVC_NERF_BLASTER[16] = { 0x44, 0x0b, 0xf6, 0x40, 0xe8, 0xd1, 0x83, 0x49, 0xa6, 0x72, 0x4d, 0xd7, 0x72, 0xc8, 0x7c, 0x82 };

BLEService NerfDeviceService = BLEService(UUID128_SVC_NERF_BLASTER);
BLEDis DeviceInformationService;

BluetoothManager::BluetoothManager() {
}

BluetoothManager::~BluetoothManager() {
}

void BluetoothManager::beginInit() {
    Bluefruit.begin();
    Bluefruit.setName("Nerf Lawgiver\n");

    DeviceInformationService.setManufacturer("Jeff Winn");
    DeviceInformationService.setFirmwareRev("2.0.0");
    DeviceInformationService.setHardwareRev("1.1.0");
    DeviceInformationService.setModel("Nerf Nemesis MXVII-10K\n");
}

void BluetoothManager::endInit() {
    Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
    Bluefruit.Advertising.addTxPower();
    Bluefruit.Advertising.addService(NerfDeviceService);
    Bluefruit.Advertising.addName();

    /* Start Advertising
     * - Enable auto advertising if disconnected
     * - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
     * - Timeout for fast mode is 30 seconds
     * - Start(timeout) with timeout = 0 will advertise forever (until connected)
     * 
     * For recommended advertising interval
     * https://developer.apple.com/library/content/qa/qa1931/_index.html   
    */
    Bluefruit.Advertising.restartOnDisconnect(true);
    Bluefruit.Advertising.setInterval(32, 244);
    Bluefruit.Advertising.setFastTimeout(30);
    Bluefruit.Advertising.start(0);
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