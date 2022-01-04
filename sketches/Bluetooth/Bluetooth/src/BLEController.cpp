#include "BLEController.h"
#include "Callbacks.h"
#include "shared/BitConverter.h"
#include "shared/Constants.h"

BLEController BLE = BLEController();

BLEController::BLEController() {
  m_blasterService = BlasterService();
  m_configService = ConfigurationService();

  m_discoveryService = BLEDis();
}

void BLEController::setCallback(RemoteCommandReceivedCallback callback) const {
  SetBluetoothCommandReceivedCallback(callback);
}

void BLEController::init(const char* name) {
  Bluefruit.begin();
  Bluefruit.setName(name);
  
  Bluefruit.ScanResponse.addName();  
  Bluefruit.Periph.begin();

  m_discoveryService.setManufacturer("Jeff Winn");
  m_discoveryService.setModel("Generic Blaster");
  m_discoveryService.begin();

  m_blasterService.begin();
  m_blasterService.init();

  m_configService.begin();
  m_configService.init();

  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addService(m_blasterService);
  Bluefruit.Advertising.addService(m_configService);
  Bluefruit.Advertising.addName();

  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);
  Bluefruit.Advertising.setFastTimeout(30);

  Bluefruit.Security.setIOCaps(false, false, false);
}

void BLEController::setPin(const char* pin) {
  if (pin == nullptr) {
    return;
  }

  Bluefruit.Security.setPIN(pin);
}

void BLEController::startAdvertising() {
  /* Start Advertising
    * - Enable auto advertising if disconnected
    * - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
    * - Timeout for fast mode is 30 seconds
    * - Start(timeout) with timeout = 0 will advertise forever (until connected)
    * 
    * For recommended advertising interval
    * https://developer.apple.com/library/content/qa/qa1931/_index.html   
  */
  Bluefruit.Advertising.start(0);
}

void BLEController::clearBonds() {
  Bluefruit.Periph.clearBonds();
}

void BLEController::setCharacteristic(const uint8_t characteristicId, const uint8_t* data) {
  switch (characteristicId) {
    case NRF52_CHR_FLYWHEEL_SPEED:
      setFlywheelSpeed(data);
      break;

    case NRF52_CHR_PUSHER_SPEED:
      setPusherSpeed(data);
      break;
    
    case NRF52_CHR_FLYWHEEL_M1_TRIM:
      setFlywheelM1TrimSpeed(data);
      break;
    
    case NRF52_CHR_FLYWHEEL_M2_TRIM:
      setFlywheelM2TrimSpeed(data);
      break;
    
    case NRF52_CHR_FLYWHEEL_NORMAL_SPEED:
      setFlywheelNormalSpeed(data);
      break;
    
    case NRF52_CHR_FLYWHEEL_LOW_SPEED:
      setFlywheelLowSpeed(data);
      break;
    
    case NRF52_CHR_FLYWHEEL_MAX_SPEED:
      setFlywheelMaxSpeed(data);
      break;
    
    case NRF52_CHR_FLYWHEEL_TRIM_VARIANCE:
      setFlywheelTrimVariance(data);
      break;
    
    case NRF52_CHR_PUSHER_NORMAL_SPEED:
      setPusherNormalSpeed(data);
      break;
    
    case NRF52_CHR_PUSHER_LOW_SPEED:
      setPusherLowSpeed(data);
      break;
    
    case NRF52_CHR_PUSHER_MAX_SPEED:
      setPusherMaxSpeed(data);
      break;
    
    case NRF52_CHR_HOPPER_LOCK_ENABLED:
      setHopperLockEnabled(data);
      break;  
  }
}

void BLEController::setFlywheelSpeed(const uint8_t* data) {
  m_blasterService.setFlywheelSpeed(data[0]);
}

void BLEController::setPusherSpeed(const uint8_t* data) {
  m_blasterService.setPusherSpeed(data[0]);
}

void BLEController::setFlywheelM1TrimSpeed(const uint8_t* data) {
  auto m1TrimValue = Convert.toFloat(data);
  m_blasterService.setFlywheelM1TrimSpeed(m1TrimValue);
}

void BLEController::setFlywheelM2TrimSpeed(const uint8_t* data) {
  auto m2TrimValue = Convert.toFloat(data);
  m_blasterService.setFlywheelM2TrimSpeed(m2TrimValue);
}

void BLEController::setFlywheelNormalSpeed(const uint8_t* data) {
  auto flywheelNormalSpeed = Convert.toInt32(data);
  m_configService.setFlywheelNormalSpeed(flywheelNormalSpeed);
}

void BLEController::setFlywheelLowSpeed(const uint8_t* data) {
  auto flywheelLowSpeed = Convert.toInt32(data);
  m_configService.setFlywheelLowSpeed(flywheelLowSpeed);
}

void BLEController::setFlywheelMaxSpeed(const uint8_t* data) {
  auto flywheelMaxSpeed = Convert.toInt32(data);
  m_configService.setFlywheelMaxSpeed(flywheelMaxSpeed);
}

void BLEController::setFlywheelTrimVariance(const uint8_t* data) {
  auto flywheelTrimVariance = Convert.toFloat(data);
  m_configService.setFlywheelTrimVariance(flywheelTrimVariance);
}

void BLEController::setPusherNormalSpeed(const uint8_t* data) {
  auto pusherNormalSpeed = Convert.toInt32(data);
  m_configService.setPusherNormalSpeed(pusherNormalSpeed);
}

void BLEController::setPusherLowSpeed(const uint8_t* data) {
  auto pusherLowSpeed = Convert.toInt32(data);
  m_configService.setPusherLowSpeed(pusherLowSpeed);
}

void BLEController::setPusherMaxSpeed(const uint8_t* data) {
  auto pusherMaxSpeed = Convert.toInt32(data);
  m_configService.setPusherMaxSpeed(pusherMaxSpeed);
}

void BLEController::setHopperLockEnabled(const uint8_t* data) {
  auto hopperLockEnabled = false;
  if (data[0] != 0) {
    hopperLockEnabled = true;
  }

  m_configService.setHopperLockEnabled(hopperLockEnabled);
}