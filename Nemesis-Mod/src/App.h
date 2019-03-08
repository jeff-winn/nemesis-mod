#ifndef APP_H
#define APP_H

#include "Controllers/FlywheelController.h"
#include "Hardware/InterruptButton.h"

class App {
    public:
        App(
            FlywheelController* flywheelController, 
            InterruptButton* revTrigger, 
            InterruptButton* firingTrigger,
            HardwareAccessLayer* p_hardware);
        
        void run();

        void onRevTriggerStateChangedCallback();
        void onFiringTriggerStateChangedCallback();

    protected:
        virtual void waitForWakeEvent();
    
    private:
        FlywheelController* m_flywheelController;
        InterruptButton* m_revTrigger;
        InterruptButton* m_firingTrigger;
        HardwareAccessLayer* hardware;
};

#endif