#ifndef SET_PIN_COMMAND_H
#define SET_PIN_COMMAND_H

#include "../Command.h"

class SetPinCommand : public Command {
    public:
        SetPinCommand() = default;

    protected:
        void executeImpl(const uint8_t* data, const uint8_t len) override;
};

#endif /* SET_PIN_COMMAND_H */