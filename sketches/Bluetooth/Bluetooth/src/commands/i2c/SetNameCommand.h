#ifndef SET_NAME_COMMAND_H
#define SET_NAME_COMMAND_H

#include "../Command.h"

class SetNameCommand : public Command {
    public:
        SetNameCommand() = default;

    protected:
        void executeImpl(const uint8_t* data, const uint8_t len) override;
};

#endif /* SET_NAME_COMMAND_H */