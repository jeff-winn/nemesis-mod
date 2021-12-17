#ifndef SET_NAME_COMMAND_H
#define SET_NAME_COMMAND_H

#include "../Command.h"

class SetNameCommand : public Command {
    public:
        SetNameCommand();
        ~SetNameCommand() override;

    protected:
        void executeImpl(uint8_t *data, uint8_t len) override;
};

#endif /* SET_NAME_COMMAND_H */