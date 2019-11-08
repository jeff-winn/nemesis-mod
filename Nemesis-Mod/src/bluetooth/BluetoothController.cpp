#include "BluetoothController.h"
#include "CustomUuid.h"
#include "Callbacks.h"

BluetoothController::BluetoothController() {
  _service = BLEService(UUID128_SVC_NERF_BLASTER);
  _flywheelSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_SPEED);

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

  _service.begin();

  _flywheelSpeed.setProperties(CHR_PROPS_READ | CHR_PROPS_WRITE);
  _flywheelSpeed.setPermission(SECMODE_OPEN, SECMODE_OPEN);
  _flywheelSpeed.setFixedLen(1);
  _flywheelSpeed.setWriteCallback(onFlywheelSpeedWriteCallback);
  _flywheelSpeed.begin();
}

void BluetoothController::endInit() {
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();

  Bluefruit.Advertising.addService(_service);
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