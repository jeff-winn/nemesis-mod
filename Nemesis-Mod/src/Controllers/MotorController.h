#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

// Defines the motor speeds available.
enum MotorSpeed {
    Low = 0,
    Normal,
    // WARNING: This value may cause physical bruising on the intended target, use with caution!
    High
};

// Provides a base implementation of a motor controller.
class MotorController {
    public:
        // Initializes the controller.
        virtual void init();

        // Starts the controller.
        void start();

        // Stops the controller.
        void stop();

        // Sets the motor speed.
        void setSpeed(MotorSpeed speed);

    protected:
        // Extension point for operations which occur on start.
        virtual void onStart();

        // Extension point for operations which occur on stop.
        virtual void onStop();
        
        // Identifies whether the controller is running.
        bool isRunning();

        // Gets the motor speed.
        MotorSpeed getSpeed();

    private:
        MotorSpeed m_speed;
        bool m_isRunning;
};

#endif