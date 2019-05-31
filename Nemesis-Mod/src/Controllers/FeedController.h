#ifndef FEED_CONTROLLER_H
#define FEED_CONTROLLER_H

#include "../Hardware/Interop/G2HighPowerMotorShield.h"
#include "../Hardware/Interop/Mainboard.h"
#include "MotorController.h"

// Defines the belt speeds (rate of fire) available.
enum class BeltSpeed {
    Normal = 0,
    High,
    Max
};

// Provides a mechanism to control the feed assembly.
class FeedController : public MotorController {
    public:
        FeedController(Mainboard* hardware, G2HighPowerMotorShield18v17* driver);

        // Initializes the controller.
        void init() override;

        // Sets the belt speed.
        void setSpeed(BeltSpeed speed);

    protected:
        int calculateMotorSpeed();
        int calculateStepFromSpeed(int speed);

        void onStart() override;
        void onStop() override;

    private:
        Mainboard* m_hardware;
        G2HighPowerMotorShield18v17* m_driver;

        BeltSpeed m_speed;
        int m_m1speed;
};

#endif