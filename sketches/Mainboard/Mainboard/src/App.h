#ifndef APP_H
#define APP_H

#include "CommandFactory.h"

void OnRemoteCommandReceivedCallback(uint8_t type, uint8_t subtype, uint8_t* data, uint8_t len);

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

        void onRemoteCommandReceived(uint8_t type, uint8_t subtype, uint8_t* data, uint8_t len);

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