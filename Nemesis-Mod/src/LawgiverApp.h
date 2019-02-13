#ifndef LAWGIVER_APP_H
#define LAWGIVER_APP_H

#include "Controllers/FlywheelController.h"
#include "Hardware/InterruptButton.h"

class LawgiverApp {
    public:
        LawgiverApp(
            FlywheelController* flywheelController, 
            InterruptButton* revTrigger, 
            InterruptButton* firingTrigger,
            HAL* hardwareAccessLayer);
        
        void init();
        void run();

        void onRevTriggerStateChangedCallback();
        void onFiringTriggerStateChangedCallback();

    protected:
        virtual void attemptToWakeTheDevice();
        virtual void waitForWakeEvent();
    
    private:
        FlywheelController* m_flywheelController;
        InterruptButton* m_revTrigger;
        InterruptButton* m_firingTrigger;
        HAL* hal;
};

#endif