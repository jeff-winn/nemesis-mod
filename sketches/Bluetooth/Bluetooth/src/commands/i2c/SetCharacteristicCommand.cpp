#include "SetCharacteristicCommand.h"

SetCharacteristicCommand::SetCharacteristicCommand(uint8_t subtype) {
    m_subtype = subtype;
}

SetCharacteristicCommand::~SetCharacteristicCommand() {        
}

void SetCharacteristicCommand::executeImpl(uint8_t *data, uint8_t len) {
    
}