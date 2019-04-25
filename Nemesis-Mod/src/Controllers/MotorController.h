#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

// Defines the flywheel speeds available.
enum FlywheelSpeed {
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

    protected:
        // Extension point for operations which occur on start.
        virtual void onStart();

        // Extension point for operations which occur on stop.
        virtual void onStop();
        
        // Identifies whether the controller is running.
        bool isRunning();

    private:
        bool m_isRunning;
};

#endif