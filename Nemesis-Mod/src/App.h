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
            HardwareAccessLayer* hardware);
        
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
        HardwareAccessLayer* m_hardware;
};

#endif