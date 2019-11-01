#include <bluefruit.h>
#include "BluetoothController.h"

BluetoothController::BluetoothController() {
    _nerfService = NerfBLEService();
    _discoveryService = BLEDis();
}

BluetoothController::~BluetoothController() {
}

void BluetoothController::beginInit(BLECharacteristic::write_cb_t onFlywheelSpeedChangedCallback, BLECharacteristic::write_cb_t onBeltSpeedChangedCallback) {
    Bluefruit.begin();
    Bluefruit.setName("Nerf Nemesis MXVII-10K");

    _discoveryService.setManufacturer("Jeff Winn");
    _discoveryService.setModel("Nerf Nemesis MXVII-10K");
    _discoveryService.setHardwareRev("1.1.0");
    _discoveryService.begin();

    _nerfService.begin();
    _nerfService.init(onFlywheelSpeedChangedCallback, onBeltSpeedChangedCallback);
}

void BluetoothController::endInit() {
    Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
    Bluefruit.Advertising.addTxPower();
    Bluefruit.Advertising.addService(_nerfService);
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