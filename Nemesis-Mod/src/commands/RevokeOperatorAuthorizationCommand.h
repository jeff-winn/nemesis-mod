#ifndef REVOKE_OPERATOR_AUTHORIZATION_COMMAND_H
#define REVOKE_OPERATOR_AUTHORIZATION_COMMAND_H

#include "../App.h"
#include "../Command.h"

// Provides a command which revokes the operator authorization to use the blaster.
class RevokeOperatorAuthorizationCommand : public Command {
    public:
        RevokeOperatorAuthorizationCommand(App* app);

        ~RevokeOperatorAuthorizationCommand() override;

    protected:
        void handleImpl(Packet_t packet) override;

    private:
        App* m_app;
};

#endif