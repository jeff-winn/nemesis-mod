#ifndef BT_READY_COMMAND_H
#define BT_READY_COMMAND_H

#include "../Command.h"

class BTReadyCommand : public Command {
    public:
        BTReadyCommand() = default;

    protected:
        void handleImpl(const uint8_t* data, const uint16_t len) override;
};

#endif /* BT_READY_COMMAND_H */