#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

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
        virtual void onStart();
        virtual void onStop();
        
        // Identifies whether the controller is running.
        bool isRunning();

    private:
        bool m_isRunning;
};

#endif