#ifndef CLEAR_BONDS_COMMAND_H
#define CLEAR_BONDS_COMMAND_H

#include "../Command.h"

class ResetCommand : public Command {
    public:
        ResetCommand() = default;

    protected:
        void executeImpl(const uint8_t* data, const uint8_t len) override;  
};

#endif /* CLEAR_BONDS_COMMAND_H */