#ifndef FLYWHEEL_CONTROLLER_H
#define FLYWHEEL_CONTROLLER_H

#include <DualG2HighPowerMotorShield.h>
#include "../Hardware/Potentiometer.h"

// Provides a mechanism to control the flywheels.
class FlywheelController {
    public:
        FlywheelController::FlywheelController(
            DualG2HighPowerMotorShield18v18* motorController,
            Potentiometer* pot1,
            Potentiometer* pot2);

        // Initializes the controller.
        virtual void init();

        // Starts the flywheels.
        virtual void start();

        // Stops the flywheels.
        virtual void stop();

    private:
        DualG2HighPowerMotorShield18v18* m_motorController;
        Potentiometer* m_pot1;
        Potentiometer* m_pot2;
};

#endif