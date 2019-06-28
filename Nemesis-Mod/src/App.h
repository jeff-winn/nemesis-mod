#ifndef APP_H
#define APP_H

#include "hardware/BluetoothManager.h"
#include "Command.h"
#include "ConfigurationSettings.h"
#include "FeedController.h"
#include "FlywheelController.h"
#include "InterruptButton.h"
#include "PolledButton.h"

// Represents the main application.
class App {
    public:
        App(
            FlywheelController* flywheelController,
            FeedController* feedController,            
            PolledButton* revTrigger, 
            PolledButton* firingTrigger,
            InterruptButton* resetButton,
            BluetoothManager* ble,
            ConfigurationSettings* config,
            Mainboard* hardware);

        ~App();
        
        // Initializes the application.
        void init();

        // Runs the application.
        void run();

        // Authenticates the operator (thereby releasing the software lock).
        void authenticate();

        // Occurs when the reset button changes state.
        void onResetButtonStateChangedCallback();

    protected:        
        Command* createCommandFromPacket(Packet_t packet);
        void handleAnyExternalCommands();

        bool shouldHandleReset();
        void handleReset();
    
    private:
        FlywheelController* m_flywheelController;
        FeedController* m_feedController;
        PolledButton* m_revTrigger;
        PolledButton* m_firingTrigger;
        InterruptButton* m_resetButton;
        BluetoothManager* m_ble;
        ConfigurationSettings* m_config;
        Mainboard* m_hardware;
};

#endif