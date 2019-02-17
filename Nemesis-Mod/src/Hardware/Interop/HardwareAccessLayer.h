#ifndef HARDWARE_ACCESS_LAYER_H
#define HARDWARE_ACCESS_LAYER_H

#include "Mainboard.h"
#include "PwmModule.h"

// Provides access to the hardware.
class HardwareAccessLayer : public Mainboard, public PwmModule {
    
};

#endif