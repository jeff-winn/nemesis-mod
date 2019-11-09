#ifndef CUSTOM_UUID_H
#define CUSTOM_UUID_H

#include <stdint.h>

// Defines the custom 128-bit UUID for the Nerf Blaster GATT service.
extern uint8_t UUID128_SVC_NERF_BLASTER[16];

// Defines the custom 128-bit UUID for the Flywheel Speed GATT characteristic.
extern uint8_t UUID128_CHR_FLYWHEEL_SPEED[16];

// Defines the custom 128-bit UUID for the Belt Speed GATT characteristic.
extern uint8_t UUID128_CHR_BELT_SPEED[16];

#endif /* CUSTOM_UUID_H */