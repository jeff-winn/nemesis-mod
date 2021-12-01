#ifndef CLEAR_BONDS_COMMAND_H
#define CLEAR_BONDS_COMMAND_H

#include "../Command.h"

class ResetCommand : public Command {
    public:
        ResetCommand();
        ~ResetCommand() override;

    protected:
        void executeImpl(uint8_t *data, uint8_t len) override;  
};

#endif /* CLEAR_BONDS_COMMAND_H */