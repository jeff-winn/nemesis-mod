#ifndef NOTIFY_READY_COMMAND_H
#define NOTIFY_READY_COMMAND_H

#include "../Command.h"

class NotifyReadyCommand : public Command {
    public:
        NotifyReadyCommand();
        ~NotifyReadyCommand() override;

    protected:
        void executeImpl(uint8_t *data, uint8_t len) override;
};

#endif /* NOTIFY_READY_COMMAND_H */