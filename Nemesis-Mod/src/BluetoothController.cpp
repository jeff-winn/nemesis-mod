#include "BluetoothController.h"
#include "Log.h"

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