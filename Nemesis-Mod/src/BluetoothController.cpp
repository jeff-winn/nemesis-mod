#include "BluetoothController.h"
#include "Log.h"

const uint32_t NOTIFICATION_INTERVAL_IN_MSECS = 10000; // 10 seconds
const uint32_t NOTIFICATION_INTERVAL_WHILE_ACTIVE_IN_MSECS = 1000; // 1 second

BluetoothController BLE = BluetoothController();

BluetoothController::BluetoothController() {
  _blasterService = BlasterService();
  _configService = ConfigurationService();

  _discoveryService = BLEDis();
}

BluetoothController::~BluetoothController() {
}

void BluetoothController::init() {
  Bluefruit.begin();
  Bluefruit.setName("Nerf Nemesis MXVII-10K");

  Bluefruit.Periph.begin();

  _discoveryService.setManufacturer("Jeff Winn");
  _discoveryService.setModel("Nerf Nemesis MXVII-10K");
  _discoveryService.begin();

  _blasterService.begin();
  _blasterService.init();

  _configService.begin();
  _configService.init();

  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addService(_blasterService);
  Bluefruit.Advertising.addService(_configService);
  Bluefruit.Advertising.addName();

  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);
  Bluefruit.Advertising.setFastTimeout(30);
}

void BluetoothController::startAdvertising() {
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

void BluetoothController::clearBonds() {
  Bluefruit.clearBonds();

  Log.println("Cleared Bluetooth bonds.");
}

void BluetoothController::notifyBeltCurrentMilliamps(uint32_t m1, bool isActive) {
  if (!Bluefruit.connected()) {
    return;
  }

  auto sendNotification = false;
  if (isActive && shouldSendNotification(lastBeltMilliampsNotifyAtMillis, NOTIFICATION_INTERVAL_WHILE_ACTIVE_IN_MSECS)) {
    sendNotification = true;
  }
  else if (!isActive && shouldSendNotification(lastBeltMilliampsNotifyAtMillis, NOTIFICATION_INTERVAL_IN_MSECS)) {
    sendNotification = true;
  }

  if (sendNotification) {
    _blasterService.notifyBeltCurrentMilliamps(m1);
    lastBeltMilliampsNotifyAtMillis = millis();
  }
}

void BluetoothController::notifyFlywheelCurrentMilliamps(uint32_t m1, uint32_t m2, bool isActive) {
  if (!Bluefruit.connected()) {
    return;
  }

  auto sendNotification = false;
  if (isActive && shouldSendNotification(lastFlywheelMilliampsNotifyAtMillis, NOTIFICATION_INTERVAL_WHILE_ACTIVE_IN_MSECS)) {
    sendNotification = true;
  }
  else if (!isActive && shouldSendNotification(lastFlywheelMilliampsNotifyAtMillis, NOTIFICATION_INTERVAL_IN_MSECS)) {
    sendNotification = true;
  }

  if (sendNotification) {
    _blasterService.notifyFlywheelCurrentMilliamps(m1, m2);
    lastFlywheelMilliampsNotifyAtMillis = millis();
  }
}

bool BluetoothController::shouldSendNotification(uint32_t lastNotificationAtMillis, uint32_t interval) {
  auto diff = millis() - lastNotificationAtMillis;
  return diff >= interval;
}