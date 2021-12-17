#ifndef PUSHER_CONTROLLER_H
#define PUSHER_CONTROLLER_H

#include "hardware/G2HighPowerMotorShield.h"
#include "MotorController.h"

// Defines the pusher speeds (rate of fire) available.
enum class PusherSpeed {
    Normal = 1,
    Low = 2,
    Max = 255
};

// Provides a mechanism to control the pusher assembly.
class PusherController : public MotorController {
    public:
        PusherController();

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

extern PusherController Pusher;

#endif /* PUSHER_CONTROLLER_H */