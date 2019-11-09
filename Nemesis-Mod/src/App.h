#ifndef APP_H
#define APP_H

#include "Command.h"

// Represents the main application.
class App {
    public:        
        // Initializes the application.
        void init();

        // Runs the application.
        void run();

        // Authenticates the operator (thereby releasing the software lock).
        void authenticate();

        // Identifies whether the operator is authorized.
        bool isAuthorized();

        // Revokes the operator authorization.
        void revokeAuthorization();

        void onRemoteCommandReceived(Packet_t packet);

    protected:        
        Command* createCommandFromPacket(Packet_t packet);
        
        void handleResetAttempt();
};

void OnBluetoothCommandReceivedCallback(uint8_t type, uint8_t* data, uint16_t len);

#endif