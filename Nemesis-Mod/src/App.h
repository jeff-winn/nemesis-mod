#ifndef APP_H
#define APP_H

#include "Controllers/FlywheelController.h"
#include "Controllers/FeedController.h"
#include "Hardware/InterruptButton.h"

class App {
    public:
        App(
            FlywheelController* flywheelController,
            FeedController* feedController,
            InterruptButton* revTrigger, 
            InterruptButton* firingTrigger,
            Mainboard* hardware);
        
        // Sets the rate of fire.
        void setSpeed(MotorSpeed speed);

        // Initializes the application.
        virtual void init();

        void run();

        void onRevTriggerStateChangedCallback();
        void onFiringTriggerStateChangedCallback();

    protected:
        virtual void waitForWakeEvent();
    
    private:
        FlywheelController* m_flywheelController;
        FeedController* m_feedController;
        InterruptButton* m_revTrigger;
        InterruptButton* m_firingTrigger;
        Mainboard* m_hardware;
};

#endif