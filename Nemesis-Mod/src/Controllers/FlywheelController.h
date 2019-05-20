#ifndef FLYWHEEL_CONTROLLER_H
#define FLYWHEEL_CONTROLLER_H

#include <DualG2HighPowerMotorShield.h>
#include "../Hardware/Potentiometer.h"
#include "MotorController.h"

// Defines the motors within the flywheel assembly.
enum FlywheelMotor {
    Motor1,
    Motor2
};

// Provides a mechanism to control the flywheel assembly.
class FlywheelController : public MotorController {
    public:
        FlywheelController(
            HardwareAccessLayer* hardware,
            DualG2HighPowerMotorShield18v18* motorController, 
            Potentiometer* motor1Potentiometer,
            Potentiometer* motor2Potentiometer);

        // Initializes the controller.
        void init() override;

        // Gets the current of the motor specified (in milliamps).
        unsigned int getMotorCurrentMilliamps(FlywheelMotor motor);

    protected:
        int calculateLimiterForSpeed(int speed);
        int calculateMotorSpeed(FlywheelMotor motor);
        float getMotorSpeedAdjustment(FlywheelMotor motor);
        int determineMotorMaximumSpeed();    
        int calculateStepFromValue(int value);

        void onStart() override;
        void onStop() override;
        
    private:
        HardwareAccessLayer* m_hardware;
        DualG2HighPowerMotorShield18v18* m_driver;
        Potentiometer* m_motor1Adjustment;
        Potentiometer* m_motor2Adjustment;

        int m_m1Speed;
        int m_m2Speed;
};

#endif