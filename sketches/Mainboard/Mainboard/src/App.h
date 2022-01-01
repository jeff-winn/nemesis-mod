#ifndef APP_H
#define APP_H

#include "CommandFactory.h"

void OnRemoteCommandReceivedCallback(const uint8_t type, const uint8_t subtype, const uint8_t* data, const uint8_t len);

// Represents the main application.
class App {
    public:
        App();
        
        // Initializes the application.
        void init();

        // Runs the application.
        void run();

        void reset();

        void clear();

        // Authenticates the operator (thereby releasing the software lock).
        void authenticate();

        // Identifies whether the operator is authorized.
        bool isAuthorized();

        // Revokes the operator authorization.
        void revokeAuthorization();

        // Occurs when a remote command has been received.
        void onRemoteCommandReceived(const uint8_t type, const uint8_t subtype, const uint8_t* data, const uint8_t len);

    protected:       
        void checkForAsyncCommands();
        
        void revFlywheels();
        void stopFlywheels();

        void startFiring();
        void stopFiring();

        bool shouldAllowRevvingFlywheels();
        bool shouldAllowFiringRounds();
        bool isLockedOut();
        bool isAlreadyFiring();

        void resetCore();

    private:
        bool m_firing;
        bool m_isAuthorized;
        CommandFactory m_commandFactory;
};

extern App Application;

#endif /* APP_H */