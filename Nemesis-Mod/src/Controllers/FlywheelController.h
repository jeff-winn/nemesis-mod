#ifndef FLYWHEEL_CONTROLLER_H
#define FLYWHEEL_CONTROLLER_H

#include <DualG2HighPowerMotorShield.h>
#include "../Hardware/Potentiometer.h"

// Defines the motors within the flywheel assembly.
enum FlywheelMotor {
    Motor1,
    Motor2
};

// Defines the flywheel speeds available.
enum FlywheelSpeed {
    Low = 0,
    Normal,
    // WARNING: This value may cause physical bruising on the intended target, use with caution!
    High
};

// Provides a mechanism to control the flywheel assembly.
class FlywheelController {
    public:
        FlywheelController(
            HardwareAccessLayer* hardware,
            DualG2HighPowerMotorShield18v18* motorController, 
            Potentiometer* motor1Potentiometer,
            Potentiometer* motor2Potentiometer,
            FlywheelSpeed speed);

        // Gets the current of the motor specified (in milliamps).
        virtual unsigned int getMotorCurrentMilliamps(FlywheelMotor motor);

        // Initializes the controller.
        virtual void init();

        // Sets the flywheel motor speed.
        virtual void setSpeed(FlywheelSpeed value);

        // Starts the flywheels.
        virtual void start();

        // Stops the flywheels.
        virtual void stop();

    protected:
        virtual float getMotorSpeedAdjustment(FlywheelMotor motor);
        virtual int determineMotorSpeed();
        
    private:
        HardwareAccessLayer* m_hardware;
        DualG2HighPowerMotorShield18v18* m_motorController;
        Potentiometer* m_motor1Adjustment;
        Potentiometer* m_motor2Adjustment;

        FlywheelSpeed m_speed;
        bool m_isRunning;
};

#endif