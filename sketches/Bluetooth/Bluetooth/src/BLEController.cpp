#include "BLEController.h"
#include "Callbacks.h"
#include "shared/BitConverter.h"
#include "shared/Constants.h"

const uint32_t NOTIFICATION_INTERVAL_IN_MSECS = 10000; // 10 seconds
const uint32_t NOTIFICATION_INTERVAL_WHILE_ACTIVE_IN_MSECS = 1000; // 1 second

BLEController BLE = BLEController();

BLEController::BLEController() {
  m_blasterService = BlasterService();
  m_configService = ConfigurationService();

  m_discoveryService = BLEDis();
}

BLEController::~BLEController() {
}

void BLEController::init(RemoteCommandReceivedCallback callback) {
  SetBluetoothCommandReceivedCallback(callback);

  Bluefruit.begin();
  Bluefruit.setName("Nerf Nemesis MXVII-10K");
  
  Bluefruit.ScanResponse.addName();  
  Bluefruit.Periph.begin();

  m_discoveryService.setManufacturer("Jeff Winn");
  m_discoveryService.setModel("Nerf Nemesis MXVII-10K");
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

void BLEController::setCharacteristic(uint8_t characteristicId, uint8_t *data, uint8_t len) {
  switch (characteristicId) {
    case NRF52_CHR_FLYWHEEL_SPEED: {
      m_blasterService.setFlywheelSpeed(data[0]);
    }
    case NRF52_CHR_BELT_SPEED: {
      m_blasterService.setBeltSpeed(data[0]);
    }
    case NRF52_CHR_FLYWHEEL_M1_TRIM: {
      auto m1TrimValue = Convert.toFloat(data);
      m_blasterService.setFlywheelM1TrimSpeed(m1TrimValue);
    }
    case NRF52_CHR_FLYWHEEL_M2_TRIM: {
      auto m2TrimValue = Convert.toFloat(data);
      m_blasterService.setFlywheelM2TrimSpeed(m2TrimValue);
    }
    case NRF52_CHR_FLYWHEEL_NORMAL_SPEED: {
      auto flywheelNormalSpeed = Convert.toInt32(data);
      m_configService.setFlywheelNormalSpeed(flywheelNormalSpeed);
    }
    case NRF52_CHR_FLYWHEEL_KID_SPEED: {
      auto flywheelKidSpeed = Convert.toInt32(data);
      m_configService.setFlywheelKidSpeed(flywheelKidSpeed);
    }
    case NRF52_CHR_FLYWHEEL_LUDICROUS_SPEED: {
      auto flywheelLudicrousSpeed = Convert.toInt32(data);
      m_configService.setFlywheelLudicrousSpeed(flywheelLudicrousSpeed);
    }
    case NRF52_CHR_FLYWHEEL_TRIM_VARIANCE: {
      auto flywheelTrimVariance = Convert.toFloat(data);
      m_configService.setFlywheelTrimVariance(flywheelTrimVariance);
    }
    case NRF52_CHR_BELT_NORMAL_SPEED: {
      auto beltNormalSpeed = Convert.toInt32(data);
      m_configService.setBeltNormalSpeed(beltNormalSpeed);
    }
    case NRF52_CHR_BELT_MEDIUM_SPEED: {
      auto beltMediumSpeed = Convert.toInt32(data);
      m_configService.setBeltMediumSpeed(beltMediumSpeed);
    }
    case NRF52_CHR_BELT_MAX_SPEED: {
      auto beltMaxSpeed = Convert.toInt32(data);
      m_configService.setBeltMaxSpeed(beltMaxSpeed);
    }
    case NRF52_CHR_HOPPER_LOCK_ENABLED: {
      auto hopperLockEnabled = false;
      if (data[0] != 0) {
        hopperLockEnabled = true;
      }

      m_configService.setHopperLockEnabled(hopperLockEnabled);
    }
  }
}