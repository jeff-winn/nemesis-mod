#ifndef APP_H
#define APP_H

#include "Commands/Command.h"
#include "Controllers/FlywheelController.h"
#include "Controllers/FeedController.h"
#include "Hardware/PolledButton.h"
#include "Hardware/Bluetooth/BluetoothAdapter.h"

// Represents the main application.
class App {
    public:
        App(
            FlywheelController* flywheelController,
            FeedController* feedController,            
            PolledButton* revTrigger, 
            PolledButton* firingTrigger,
            BluetoothAdapter* ble,
            Mainboard* hardware);
        
        // Initializes the application.
        void init();

        // Runs the application.
        void run();

        // Authenticates the operator (thereby releasing the software lock).
        void authenticate();

    protected:        
        Command* createCommandFromPacket(Packet_t packet);
        void handleAnyExternalCommands();
    
    private:
        FlywheelController* m_flywheelController;
        FeedController* m_feedController;
        PolledButton* m_revTrigger;
        PolledButton* m_firingTrigger;
        Mainboard* m_hardware;
        BluetoothAdapter* m_ble;
};

#endif