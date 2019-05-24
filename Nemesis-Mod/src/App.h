#ifndef APP_H
#define APP_H

#include "Controllers/BluetoothController.h"
#include "Controllers/FlywheelController.h"
#include "Controllers/FeedController.h"
#include "Hardware/InterruptButton.h"
#include "Hardware/PolledButton.h"

class App {
    public:
        App(
            FlywheelController* flywheelController,
            FeedController* feedController,            
            InterruptButton* revTrigger, 
            PolledButton* firingTrigger,
            BluetoothController* bluetoothController,
            Mainboard* hardware);
        
        // Initializes the application.
        virtual void init();

        void run();
        void onRevTriggerStateChangedCallback();

    protected:
        virtual void waitForWakeEvent();
    
    private:
        FlywheelController* m_flywheelController;
        FeedController* m_feedController;
        InterruptButton* m_revTrigger;
        PolledButton* m_firingTrigger;
        BluetoothController* m_bluetoothController;
        Mainboard* m_hardware;
};

#endif