#include "src/BLEController.h"
#include "src/commands/I2cCommandFactory.h"
#include "src/I2cController.h"

void setup() {
    BLE.init(OnBluetoothCommandReceived);

    I2CBus.init(OnI2cPacketReceived);
    I2CBus.notifyReady();
}

void loop() {
    I2CBus.checkForAsyncCommands();
    delay(10);
}

void OnI2cPacketReceived(uint8_t type, uint8_t subtype, uint8_t *data, uint8_t len) {
    auto command = I2cCommands.create(type, subtype);
    if (command != NULL) {
        command->execute(data, len);
        delete command;
    }
}

void OnBluetoothCommandReceived(uint8_t type, uint8_t subtype, uint8_t *data, uint8_t len) {
    I2CBus.sendPacket(type, subtype, data, len);    
}