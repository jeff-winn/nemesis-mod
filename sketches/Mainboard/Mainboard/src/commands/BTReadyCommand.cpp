#include "BTReadyCommand.h"

#include "../ConfigurationSettings.h"
#include "../hardware/NRF52.h"
#include "../shared/Constants.h"

void BTReadyCommand::handleImpl(const uint8_t* data, const uint16_t len) {
    BT.setCharacteristic(NRF52_CHR_FLYWHEEL_SPEED, (uint8_t)0x01);
    BT.setCharacteristic(NRF52_CHR_PUSHER_SPEED, (uint8_t)0x01);    
    BT.setCharacteristic(NRF52_CHR_FLYWHEEL_M1_TRIM, Settings.getFlywheelM1TrimAdjustment());
    BT.setCharacteristic(NRF52_CHR_FLYWHEEL_M2_TRIM, Settings.getFlywheelM2TrimAdjustment());
    BT.setCharacteristic(NRF52_CHR_FLYWHEEL_NORMAL_SPEED, Settings.getFlywheelNormalSpeed());
    BT.setCharacteristic(NRF52_CHR_FLYWHEEL_LOW_SPEED, Settings.getFlywheelLowSpeed());
    BT.setCharacteristic(NRF52_CHR_FLYWHEEL_MAX_SPEED, Settings.getFlywheelMaxSpeed());
    BT.setCharacteristic(NRF52_CHR_FLYWHEEL_TRIM_VARIANCE, Settings.getFlywheelTrimVariance());
    BT.setCharacteristic(NRF52_CHR_PUSHER_NORMAL_SPEED, Settings.getPusherNormalSpeed());
    BT.setCharacteristic(NRF52_CHR_PUSHER_LOW_SPEED, Settings.getPusherLowSpeed());
    BT.setCharacteristic(NRF52_CHR_PUSHER_MAX_SPEED, Settings.getPusherMaxSpeed());
    BT.setCharacteristic(NRF52_CHR_HOPPER_LOCK_ENABLED, Settings.isHopperLockEnabled());
    
    BT.setName(Settings.getName());
    BT.setPin(Settings.getPairingPin());
    
    BT.startAdvertising();
}