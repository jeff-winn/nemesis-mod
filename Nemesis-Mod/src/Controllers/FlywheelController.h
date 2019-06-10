#ifndef FLYWHEEL_CONTROLLER_H
#define FLYWHEEL_CONTROLLER_H

#include <DualG2HighPowerMotorShield.h>
#include "../Hardware//Interop/Mainboard.h"
#include "MotorController.h"

// Defines the flywheel speeds available.
enum class FlywheelSpeed {
    Normal = 0,
    Medium,
    // WARNING: This value may cause physical bruising on the intended target, use with caution!
    Max
};

// Defines the motors within the flywheel assembly.
enum class FlywheelMotor {
    Motor1,
    Motor2
};

// Provides a mechanism to control the flywheel assembly.
class FlywheelController : public MotorController {
    public:
        FlywheelController(
            Mainboard* hardware,
            DualG2HighPowerMotorShield18v18* motorController);

        ~FlywheelController();
            
        // Initializes the controller.
        void init() override;

        // Gets the current of the motor specified (in milliamps).
        unsigned int getMotorCurrentMilliamps(FlywheelMotor motor);

        // Sets the flywheel speed.
        void setSpeed(FlywheelSpeed speed);

        // Sets the motor speed adjustment.
        void setMotorSpeedAdjustment(FlywheelMotor motor, float adjustment);

    protected:
        int calculateLimiterForSpeed(int speed);
        int calculateMotorSpeed(FlywheelMotor motor);
        float getMotorSpeedAdjustment(FlywheelMotor motor);
        int determineMotorMaximumSpeed();    
        int calculateStepFromValue(int value);

        void onStart() override;
        void onStop() override;
        
    private:
        Mainboard* m_hardware;
        DualG2HighPowerMotorShield18v18* m_driver;

        FlywheelSpeed m_speed;
        int m_m1Speed;
        int m_m2Speed;
        float m_m1MotorAdjustment;
        float m_m2MotorAdjustment;
};

#endif