#ifndef SET_CHARACTERISTIC_COMMAND_H
#define SET_CHARACTERISTIC_COMMAND_H

#include "../Command.h"

class SetCharacteristicCommand : public Command {
    public:
        SetCharacteristicCommand(uint8_t characteristicId);
    
    protected:
        void executeImpl(const uint8_t* data, const uint8_t len) override;
    
    private:
        uint8_t m_characteristicId;
};

#endif /* SET_CHARACTERISTIC_COMMAND_H */