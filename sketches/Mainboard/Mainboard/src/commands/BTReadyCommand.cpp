#include "BTReadyCommand.h"

#include "../ConfigurationSettings.h"
#include "../hardware/NRF52.h"
#include "../shared/Constants.h"

BTReadyCommand::BTReadyCommand() {    
}

BTReadyCommand::~BTReadyCommand() {
}

void BTReadyCommand::handleImpl(uint8_t* data, uint16_t len) {
    BT.setCharacteristic(NRF52_CHR_FLYWHEEL_SPEED, (uint8_t)0x01);
    BT.setCharacteristic(NRF52_CHR_BELT_SPEED, (uint8_t)0x01);    
    BT.setCharacteristic(NRF52_CHR_FLYWHEEL_M1_TRIM, Settings.getFlywheelM1TrimAdjustment());
    BT.setCharacteristic(NRF52_CHR_FLYWHEEL_M2_TRIM, Settings.getFlywheelM2TrimAdjustment());
    
    BT.startAdvertising();
}