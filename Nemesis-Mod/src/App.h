#ifndef APP_H
#define APP_H

#include "Controllers/FlywheelController.h"
#include "Controllers/FeedController.h"
#include "Hardware/InterruptButton.h"
#include "Hardware/PolledButton.h"
#include "Hardware/Bluetooth/BluetoothAdapter.h"

class App {
    public:
        App(
            FlywheelController* flywheelController,
            FeedController* feedController,            
            InterruptButton* revTrigger, 
            PolledButton* firingTrigger,
            Mainboard* hardware,
            BluetoothAdapter* ble);
        
        // Initializes the application.
        void init();

        void run();
        void onRevTriggerStateChangedCallback();

    protected:
        void handleAnyExternalCommands();
        void waitForWakeEvent();
    
    private:
        FlywheelController* m_flywheelController;
        FeedController* m_feedController;
        InterruptButton* m_revTrigger;
        PolledButton* m_firingTrigger;
        Mainboard* m_hardware;
        BluetoothAdapter* m_ble;
};

#endif