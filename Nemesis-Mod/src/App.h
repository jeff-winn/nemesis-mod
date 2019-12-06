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

        void reset();

        void clear();

        // Authenticates the operator (thereby releasing the software lock).
        void authenticate();

        // Identifies whether the operator is authorized.
        bool isAuthorized();

        // Revokes the operator authorization.
        void revokeAuthorization();

        void onRemoteCommandReceived(uint8_t type, uint8_t* data, uint16_t len, uint8_t subtype);

    protected:        
        Command* createCommandFromPacket(uint8_t type, uint8_t subtype);
        
        void waitForRevTriggerToBePressed();
        void sendCurrentNotifications();

        void resetCore();

    private:
        uint32_t m_revvedAtMillis;
};

extern App Application;

#endif /* APP_H */