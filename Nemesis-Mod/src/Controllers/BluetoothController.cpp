#include "BluetoothController.h"

BluetoothController::BluetoothController(Adafruit_BluefruitLE_SPI* ble) {
    m_ble = ble;
}

void BluetoothController::init() {
    m_ble->begin();
    m_ble->factoryReset();

    m_ble->setMode(BLUEFRUIT_MODE_COMMAND);
    m_ble->sendCommandCheckOK("AT+GAPDEVNAME=Nerf Nemesis MXVII-10K");
    
    m_ble->setMode(BLUEFRUIT_MODE_DATA);
}