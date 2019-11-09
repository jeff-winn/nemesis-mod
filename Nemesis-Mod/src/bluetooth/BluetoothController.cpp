#include "BluetoothController.h"
#include "CustomUuid.h"

BluetoothController::BluetoothController() {
  _speedService = BlasterSpeedService();

  _discoveryService = BLEDis();
}

BluetoothController::~BluetoothController() {
}

void BluetoothController::beginInit() {
  Bluefruit.begin();
  Bluefruit.setName("Nerf Nemesis MXVII-10K");

  Bluefruit.Periph.begin();

  _discoveryService.setManufacturer("Jeff Winn");
  _discoveryService.setModel("Nerf Nemesis MXVII-10K");
  _discoveryService.begin();

  _speedService.begin();
  _speedService.init();
}

void BluetoothController::endInit() {
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();

  Bluefruit.Advertising.addService(_speedService);
  Bluefruit.Advertising.addName();

  /* Start Advertising
    * - Enable auto advertising if disconnected
    * - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
    * - Timeout for fast mode is 30 seconds
    * - Start(timeout) with timeout = 0 will advertise forever (until connected)
    * 
    * For recommended advertising interval
    * https://developer.apple.com/library/content/qa/qa1931/_index.html   
  */
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);
  Bluefruit.Advertising.setFastTimeout(30);
  Bluefruit.Advertising.start(0);
}