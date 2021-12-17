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
    BT.setCharacteristic(NRF52_CHR_FLYWHEEL_NORMAL_SPEED, Settings.getFlywheelNormalSpeed());
    BT.setCharacteristic(NRF52_CHR_FLYWHEEL_KID_SPEED, Settings.getFlywheelKidSpeed());
    BT.setCharacteristic(NRF52_CHR_FLYWHEEL_LUDICROUS_SPEED, Settings.getFlywheelLudicrousSpeed());
    BT.setCharacteristic(NRF52_CHR_FLYWHEEL_TRIM_VARIANCE, Settings.getFlywheelTrimVariance());
    BT.setCharacteristic(NRF52_CHR_BELT_NORMAL_SPEED, Settings.getFeedNormalSpeed());
    BT.setCharacteristic(NRF52_CHR_BELT_LOW_SPEED, Settings.getFeedLowSpeed());
    BT.setCharacteristic(NRF52_CHR_BELT_MAX_SPEED, Settings.getFeedMaxSpeed());
    BT.setCharacteristic(NRF52_CHR_HOPPER_LOCK_ENABLED, Settings.isHopperLockEnabled());
    
    BT.setName(Settings.getName());
    BT.setPin(Settings.getPairingPin());
    
    BT.startAdvertising();
}