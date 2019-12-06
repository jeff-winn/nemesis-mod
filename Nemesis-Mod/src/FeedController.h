#ifndef FEED_CONTROLLER_H
#define FEED_CONTROLLER_H

#include "MotorController.h"

// Defines the belt speeds (rate of fire) available.
enum class BeltSpeed {
    Normal = 1,
    Medium = 2,
    Max = 255
};

// Provides a mechanism to control the feed assembly.
class FeedController : public MotorController {
    public:        
        // Initializes the controller.
        void init(ConfigurationSettings* settings) override;

        // Gets the current of the motor specified (in milliamps).
        unsigned int getMotorCurrentMilliamps();

        // Gets the belt speed.
        BeltSpeed getSpeed();

        // Sets the belt speed.
        void setSpeed(BeltSpeed speed);

    protected:
        int calculateMotorSpeed();
        int calculateStepFromSpeed(int speed);

        void onStart() override;
        void onStop() override;

        void updateDriver();
        
    private:
        int m_normalSpeed;
        int m_mediumSpeed;
        int m_maxSpeed;

        BeltSpeed m_speed;
        int m_m1speed;
};

extern FeedController Belt;

#endif /* FEED_CONTROLLER_H */