#ifndef APP_H
#define APP_H

#include "AuthenticationToken_t.h"
#include "Command.h"

// Represents the main application.
class App {
    public:        
        // Initializes the application.
        void init();

        // Runs the application.
        void run();

        // Authenticates the operator (thereby releasing the software lock).
        void authenticate(AuthenticationToken_t token);

        // Identifies whether the operator is authorized.
        bool isAuthorized();

        // Revokes the operator authorization.
        void revokeAuthorization();

    protected:        
        Command* createCommandFromPacket(Packet_t packet);
        void handleAnyExternalCommands();
        void handleResetAttempt();
};

#endif