#include "Callbacks.h"
#include "RemoteCommandReceivedCallback.h"

void onFlywheelSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
  onBluetoothRemoteCommandReceivedCallback(200, data, len);
}

void onBeltSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len) {
  onBluetoothRemoteCommandReceivedCallback(100, data, len);
}