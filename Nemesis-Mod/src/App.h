#ifndef APP_H
#define APP_H

#include "Controllers/FlywheelController.h"
#include "Hardware/PolledButton.h"

class App {
    public:
        App(
            FlywheelController* flywheelController, 
            PolledButton* revTrigger, 
            PolledButton* firingTrigger,
            HardwareAccessLayer* p_hardware);
        
        void init();
        void run();

        void onRevTriggerStateChangedCallback();
        void onFiringTriggerStateChangedCallback();

    protected:
        virtual void waitForWakeEvent();
    
    private:
        FlywheelController* m_flywheelController;
        PolledButton* m_revTrigger;
        PolledButton* m_firingTrigger;
        HardwareAccessLayer* hardware;
};

#endif