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
            HardwareAccessLayer* p_hardware);
        
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
        HardwareAccessLayer* hardware;
};

#endif