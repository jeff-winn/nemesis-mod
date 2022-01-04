#include "src/BLEController.h"
#include "src/commands/I2cCommandFactory.h"
#include "src/I2cController.h"

void setup() {
    BLE.setCallback(OnBluetoothCommandReceived);

    I2CBus.init(OnI2cPacketReceived);
    I2CBus.notifyReady();
}

void loop() {
    I2CBus.checkForAsyncCommands();
}

void OnI2cPacketReceived(const uint8_t type, const uint8_t subtype, const uint8_t* data, const uint8_t len) {
    auto command = I2cCommands.create(type, subtype);
    if (command != nullptr) {
        command->execute(data, len);
        delete command;
    }
}

void OnBluetoothCommandReceived(const uint8_t type, const uint8_t subtype, const uint8_t* data, const uint8_t len) {
    I2CBus.sendPacket(type, subtype, data, len);    
}