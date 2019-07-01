#ifndef AUTHENTICATE_OPERATOR_COMMAND_H
#define AUTHENTICATE_OPERATOR_COMMAND_H

#include "../App.h"
#include "../Command.h"

// Provides a command to authenticate the operator.
class AuthenticateOperatorCommand : public Command {
    public:
        AuthenticateOperatorCommand(App* app);

        ~AuthenticateOperatorCommand() override;

        bool requiresAuthorization() override;

    protected:
        void handleImpl(Packet_t packet) override;

    private:
        App* m_app;
};

#endif