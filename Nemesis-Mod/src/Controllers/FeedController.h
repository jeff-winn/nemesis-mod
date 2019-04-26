#ifndef FEED_CONTROLLER_H
#define FEED_CONTROLLER_H

#include "../Hardware/Interop/G2HighPowerMotorShield.h"
#include "../Hardware/Interop/HardwareAccessLayer.h"
#include "MotorController.h"

// Provides a mechanism to control the feed assembly.
class FeedController : public MotorController {
    public:
        FeedController(HardwareAccessLayer* hardware, G2HighPowerMotorShield18v17* driver, MotorSpeed speed);

        // Initializes the controller.
        virtual void init();

    protected:
        int calculateMotorSpeed();

        // Extension point for operations which occur on start.
        virtual void onStart();

        // Extension point for operations which occur on stop.
        virtual void onStop();

    private:
        HardwareAccessLayer* m_hardware;
        G2HighPowerMotorShield18v17* m_driver;

        MotorSpeed m_speed;
};

#endif