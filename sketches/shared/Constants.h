#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdint.h>

// Defines the I2C address of the slave NRF52840 device.
const uint8_t NRF52840_I2C_ADDR = 0x1A;

const uint8_t NRF52_CID_SET_CONFIG = 0x0A;
const uint8_t NRF52_CID_SET_TRANSMIT_COUNT = 0x0B;
const uint8_t NRF52_CID_START_ADVERTISING = 0x01;
const uint8_t NRF52_CID_RESET = 0x02;
const uint8_t NRF52_CID_SET_CHARACTERISTIC = 0x03;
const uint8_t NRF52_CID_SET_PIN = 0x04;
const uint8_t NRF52_CID_SET_NAME = 0x05;
const uint8_t NRF52_CID_PUSHER_SPEED = 0x64;
const uint8_t NRF52_CID_FLYWHEEL_SPEED = 0xC8;
const uint8_t NRF52_CID_FLYWHEEL_TRIM = 0xC9;
const uint8_t NRF52_CID_READY = 0xFF;

const uint8_t NRF52_CHR_FLYWHEEL_SPEED = 0x01;
const uint8_t NRF52_CHR_PUSHER_SPEED = 0x02;
const uint8_t NRF52_CHR_FLYWHEEL_M1_TRIM = 0x03;
const uint8_t NRF52_CHR_FLYWHEEL_M2_TRIM = 0x04;
const uint8_t NRF52_CHR_FLYWHEEL_NORMAL_SPEED = 0x05;
const uint8_t NRF52_CHR_FLYWHEEL_LOW_SPEED = 0x06;
const uint8_t NRF52_CHR_FLYWHEEL_MAX_SPEED = 0x07;
const uint8_t NRF52_CHR_FLYWHEEL_TRIM_VARIANCE = 0x08;
const uint8_t NRF52_CHR_PUSHER_LOW_SPEED = 0x09;
const uint8_t NRF52_CHR_PUSHER_NORMAL_SPEED = 0x10;
const uint8_t NRF52_CHR_PUSHER_MAX_SPEED = 0x11;
const uint8_t NRF52_CHR_HOPPER_LOCK_ENABLED = 0x12;

#endif /* CONSTANTS_H */