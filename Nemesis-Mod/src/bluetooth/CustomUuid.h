#ifndef CUSTOM_UUID_H
#define CUSTOM_UUID_H

#include <stdint.h>

// Defines the custom 128-bit UUID for the Blaster Speed GATT service.
extern uint8_t UUID128_SVC_NERF_BLASTER[16];

// Defines the custom 128-bit UUID for the Flywheel Speed GATT characteristic.
extern uint8_t UUID128_CHR_FLYWHEEL_SPEED[16];

// Defines the custom 128-bit UUID for the Belt Speed GATT characteristic.
extern uint8_t UUID128_CHR_BELT_SPEED[16];

// Defines the custom 128-bit UUID for the Configuration GATT service.
extern uint8_t UUID128_SVC_CONFIGURATION[16];

// Defines the custom 128-bit UUID for the Flywheel normal speed GATT characteristic.
extern uint8_t UUID128_CHR_FLYWHEEL_NORMAL_SPEED[16];

// Defines the custom 128-bit UUID for the Flywheel trim variance GATT characteristic.
extern uint8_t UUID128_CHR_FLYWHEEL_TRIM_VARIANCE[16];

#endif /* CUSTOM_UUID_H */