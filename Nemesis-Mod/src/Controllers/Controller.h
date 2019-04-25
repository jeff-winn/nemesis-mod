#ifndef CONTROLLER_H
#define CONTROLLER_H

// Provides a base implementation of a controller.
class Controller {
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