#ifndef SET_CHARACTERISTIC_COMMAND_H
#define SET_CHARACTERISTIC_COMMAND_H

#include "../Command.h"

class SetCharacteristicCommand : public Command {
    public:
        SetCharacteristicCommand(uint8_t subtype);
        ~SetCharacteristicCommand() override;
    
    protected:
        void executeImpl(uint8_t *data, uint8_t len) override;
    
    private:
        uint8_t m_subtype;
};

#endif /* SET_CHARACTERISTIC_COMMAND_H */