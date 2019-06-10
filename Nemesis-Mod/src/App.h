#ifndef APP_H
#define APP_H

#include "hardware/BluetoothManager.h"
#include "Command.h"
#include "FlywheelController.h"
#include "FeedController.h"
#include "PolledButton.h"

// Represents the main application.
class App {
    public:
        App(
            FlywheelController* flywheelController,
            FeedController* feedController,            
            PolledButton* revTrigger, 
            PolledButton* firingTrigger,
            BluetoothManager* ble,
            Mainboard* hardware);

        ~App();
        
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
        BluetoothManager* m_ble;
};

#endif