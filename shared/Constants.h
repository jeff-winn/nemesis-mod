#ifndef CONSTANTS_H
#define CONSTANTS_H

// Defines the I2C address of the slave NRF52840 device.
const uint8_t NRF52840_I2C_ADDR = 0x1A;

const uint8_t NRF52_CID_SET_CONFIG = 0x0A;

const uint8_t NRF52_CID_START_ADVERTISING = 0x01;
const uint8_t NRF52_CID_CLEAR_BONDS = 0x02;

const uint8_t NRF52_CID_BELT_SPEED = 0x64;

const uint8_t NRF52_CID_FLYWHEEL_SPEED = 0xC8;
const uint8_t NRF52_CID_FLYWHEEL_TRIM = 0xC9;

#endif /* CONSTANTS_H */