#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include "ConfigurationSettings.h"

// Provides a base implementation of a motor controller.
class MotorController {
    public:
        virtual void init(ConfigurationSettings* settings);

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