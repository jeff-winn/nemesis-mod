#ifndef DEAUTHORIZE_OPERATOR_COMMAND_H
#define DEAUTHORIZE_OPERATOR_COMMAND_H

#include "../App.h"
#include "../Command.h"

class DeauthorizeOperatorCommand : public Command {
    public:
        DeauthorizeOperatorCommand(App* app);

        ~DeauthorizeOperatorCommand() override;

    protected:
        void handleImpl(Packet_t packet) override;

    private:
        App* m_app;
};

#endif