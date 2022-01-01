#ifndef SET_TRANSMIT_COUNT_COMMAND_H
#define SET_TRANSMIT_COUNT_COMMAND_H

#include "../Command.h"

class SetTransmitCountCommand : public Command {
    public:
        SetTransmitCountCommand() = default;
        
    protected:
        void executeImpl(uint8_t *data, uint8_t len) override;  
};

#endif /* SET_TRANSMIT_COUNT_COMMAND_H */