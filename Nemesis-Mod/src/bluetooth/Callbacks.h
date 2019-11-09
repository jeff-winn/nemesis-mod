#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <bluefruit.h>

void onFlywheelSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len);
void onBeltSpeedWriteCallback(uint16_t conn_hdl, BLECharacteristic* chr, uint8_t* data, uint16_t len);

#endif