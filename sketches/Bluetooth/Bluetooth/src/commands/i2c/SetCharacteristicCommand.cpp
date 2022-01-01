#include "SetCharacteristicCommand.h"
#include "../../BLEController.h"

SetCharacteristicCommand::SetCharacteristicCommand(uint8_t characteristicId) {
    m_characteristicId = characteristicId;
}

void SetCharacteristicCommand::executeImpl(const uint8_t* data, const uint8_t len) {
    BLE.setCharacteristic(m_characteristicId, data, len);
}