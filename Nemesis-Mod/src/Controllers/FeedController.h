#ifndef FEED_CONTROLLER_H
#define FEED_CONTROLLER_H

#include "../Hardware/Interop/G2HighPowerMotorShield.h"
#include "../Hardware/Interop/HardwareAccessLayer.h"
#include "Controller.h"

// Provides a mechanism to control the feed assembly.
class FeedController : public Controller {
    public:
        FeedController(HardwareAccessLayer* hardware, G2HighPowerMotorShield18v17* motorController);

        // Initializes the controller.
        virtual void init();

    protected:
        // Extension point for operations which occur on start.
        virtual void onStart();

        // Extension point for operations which occur on stop.
        virtual void onStop();

    private:
        HardwareAccessLayer* m_hardware;
        G2HighPowerMotorShield18v17* m_motorController;
};

#endif