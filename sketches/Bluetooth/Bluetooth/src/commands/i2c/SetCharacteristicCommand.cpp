#include "SetCharacteristicCommand.h"
#include "../../BLEController.h"

SetCharacteristicCommand::SetCharacteristicCommand(uint8_t characteristicId) {
    m_characteristicId = characteristicId;
}

SetCharacteristicCommand::~SetCharacteristicCommand() {        
}

void SetCharacteristicCommand::executeImpl(uint8_t *data, uint8_t len) {
    BLE.setCharacteristic(m_characteristicId, data, len);
}