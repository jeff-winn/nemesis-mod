#ifndef FLYWHEEL_CONTROLLER_H
#define FLYWHEEL_CONTROLLER_H

#include "MotorController.h"

// Defines the flywheel speeds available.
enum class FlywheelSpeed {
    Normal = 1,
    Medium = 2,
    // WARNING: This value may cause physical bruising on the intended target, use with caution!
    Max = 255
};

// Defines the motors within the flywheel assembly.
enum class FlywheelMotor {
    Motor1 = 1,
    Motor2 = 2
};

// Provides a mechanism to control the flywheel assembly.
class FlywheelController : public MotorController {
    public:            
        // Initializes the controller.
        void init(ConfigurationSettings* settings) override;

        // Gets the current of the motor specified (in milliamps).
        unsigned int getMotorCurrentMilliamps(FlywheelMotor motor);

        // Gets the flywheel speed.
        FlywheelSpeed getSpeed();

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

        void updateDrivers();

        void onStart() override;
        void onStop() override;
        
    private:
        FlywheelSpeed m_speed;
        int m_m1Speed;
        int m_m2Speed;

        int m_normalSpeed;
        int m_mediumSpeed;
        int m_maxSpeed;
        float m_trimVariance;
        float m_m1TrimAdjustment;
        float m_m2TrimAdjustment;
};

extern FlywheelController Flywheels;

#endif /* FLYWHEEL_CONTROLLER_H */