#ifndef FLYWHEEL_CONTROLLER_H
#define FLYWHEEL_CONTROLLER_H

#include <DualG2HighPowerMotorShield.h>
#include "../Hardware/Potentiometer.h"

// Defines the motors within the flywheel assembly.
enum FlywheelMotor {
    Motor1,
    Motor2
};

// Provides a mechanism to control the flywheel assembly.
class FlywheelController {
    public:
        FlywheelController::FlywheelController(
            DualG2HighPowerMotorShield18v18* motorController);

        // Gets the current of the motor specified (in milliamps).
        virtual unsigned int getMotorCurrentMilliamps(FlywheelMotor motor);

        // Initializes the controller.
        virtual void init();

        // Starts the flywheels.
        virtual void start();

        // Stops the flywheels.
        virtual void stop();

    private:
        DualG2HighPowerMotorShield18v18* m_motorController;
};

#endif