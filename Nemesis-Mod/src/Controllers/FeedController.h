#ifndef FEED_CONTROLLER_H
#define FEED_CONTROLLER_H

#include "../Hardware/Interop/G2HighPowerMotorShield.h"
#include "../Hardware/Interop/HardwareAccessLayer.h"
#include "MotorController.h"

// Provides a mechanism to control the feed assembly.
class FeedController : public MotorController {
    public:
        FeedController(HardwareAccessLayer* hardware, G2HighPowerMotorShield18v17* driver);

        // Initializes the controller.
        virtual void init();

    protected:
        virtual int calculateMotorSpeed();
        virtual int calculateStepFromValue(int value);

        virtual void onStart();
        virtual void onStop();

    private:
        HardwareAccessLayer* m_hardware;
        G2HighPowerMotorShield18v17* m_driver;

        int m_speed;
};

#endif