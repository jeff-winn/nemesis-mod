#ifndef START_ADVERTISING_COMMAND_H
#define START_ADVERTISING_COMMAND_H

#include "../Command.h"

class StartAdvertisingCommand : public Command {
    public:
        StartAdvertisingCommand() = default;

    protected:
        void executeImpl(uint8_t *data, uint8_t len) override;
};

#endif /* START_ADVERTISING_COMMAND_H */