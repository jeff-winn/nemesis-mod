#ifndef FEED_CONTROLLER_H
#define FEED_CONTROLLER_H

#include "hardware/G2HighPowerMotorShield.h"
#include "MotorController.h"

// Defines the pusher speeds (rate of fire) available.
enum class PusherSpeed {
    Normal = 1,
    Low = 2,
    Max = 255
};

// Provides a mechanism to control the feed assembly.
class FeedController : public MotorController {
    public:
        FeedController();

        // Initializes the controller.
        void init() override;

        // Gets the current of the motor specified (in milliamps).
        unsigned int getMotorCurrentMilliamps();

        // Gets the pusher speed.
        PusherSpeed getSpeed();

        // Sets the pusher speed.
        void setSpeed(PusherSpeed speed);

    protected:
        int calculateMotorSpeed();
        int calculateStepFromSpeed(int speed);

        void onStart() override;
        void onStop() override;

        void updateDriver();
        
    private:
        G2HighPowerMotorShield18v17 m_driver;

        PusherSpeed m_speed;
        int m_m1speed;
};

extern FeedController Belt;

#endif /* FEED_CONTROLLER_H */