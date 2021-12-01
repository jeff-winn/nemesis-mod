#ifndef BT_READY_COMMAND_H
#define BT_READY_COMMAND_H

#include "../Command.h"

class BTReadyCommand : public Command {
    public:
        BTReadyCommand();
        ~BTReadyCommand() override;

    protected:
        void handleImpl(uint8_t* data, uint16_t len) override;
};

#endif /* BT_READY_COMMAND_H */