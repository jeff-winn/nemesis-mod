#include "BluetoothController.h"
#include "CustomUuid.h"

BluetoothController::BluetoothController() {
    _service = BLEService(UUID128_SVC_NERF_BLASTER);
    _flywheelSpeed = BLECharacteristic(UUID128_CHR_FLYWHEEL_SPEED);

    _discoveryService = BLEDis();
}

BluetoothController::~BluetoothController() {
}

void BluetoothController::beginInit() {
  Serial.println("Initializing the bluetooth controller");
  Bluefruit.begin();
  Bluefruit.setName("Nerf Nemesis MXVII-10K");
  
  Bluefruit.Periph.setConnectCallback(connect_callback);
  Bluefruit.Periph.setDisconnectCallback(disconnect_callback);
  Bluefruit.Periph.begin();

  Serial.println("Configuring the Device Information Service");
  _discoveryService.setManufacturer("Jeff Winn");
  _discoveryService.setModel("Nerf Nemesis MXVII-10K");
  _discoveryService.begin();

  _service.begin();
  _flywheelSpeed.setProperties(CHR_PROPS_READ);
  _flywheelSpeed.setPermission(SECMODE_OPEN, SECMODE_NO_ACCESS);
  _flywheelSpeed.setFixedLen(2);
  _flywheelSpeed.begin();

  uint8_t data[2] = { 0x00, 0x00 };
  _flywheelSpeed.write(data, 2);

    // Bluefruit.begin();
    // Bluefruit.setName("Nerf Nemesis MXVII-10K");

    // Bluefruit.Periph.setConnectCallback(connect_callback);
    // Bluefruit.Periph.setDisconnectCallback(disconnect_callback);
    // Bluefruit.Periph.begin();

    // _discoveryService.setManufacturer("Jeff Winn");
    // _discoveryService.setModel("Nerf Nemesis MXVII-10K");
    // _discoveryService.setHardwareRev("1.1.0");
    // _discoveryService.begin();

    // _customService.begin();
    // _customService.init();
}

void connect_callback(uint16_t conn_handle)
{
  // Get the reference to current connection
  BLEConnection* connection = Bluefruit.Connection(conn_handle);
 
  char central_name[32] = { 0 };
  connection->getPeerName(central_name, sizeof(central_name));
 
  Serial.print("Connected to ");
  Serial.println(central_name);
}

 /* Callback invoked when a connection is dropped
 * @param conn_handle connection where this event happens
 * @param reason is a BLE_HCI_STATUS_CODE which can be found in ble_hci.h
 */
void disconnect_callback(uint16_t conn_handle, uint8_t reason)
{
  (void) conn_handle;
  (void) reason;
 
  Serial.print("Disconnected, reason = 0x"); Serial.println(reason, HEX);
  Serial.println("Advertising!");
}

void BluetoothController::endInit() {
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();

  Bluefruit.Advertising.addService(_service);
  Bluefruit.Advertising.addName();

  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);
  Bluefruit.Advertising.setFastTimeout(30);
  Bluefruit.Advertising.start(0);

  Serial.println("Ready Player One!!");
  Serial.println("\nAdvertising...");
  
    // Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
    // Bluefruit.Advertising.addTxPower();
    // Bluefruit.Advertising.addService(_customService);
    // Bluefruit.Advertising.addName();

    // /* Start Advertising
    //  * - Enable auto advertising if disconnected
    //  * - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
    //  * - Timeout for fast mode is 30 seconds
    //  * - Start(timeout) with timeout = 0 will advertise forever (until connected)
    //  * 
    //  * For recommended advertising interval
    //  * https://developer.apple.com/library/content/qa/qa1931/_index.html   
    // */
    // Bluefruit.Advertising.restartOnDisconnect(true);
    // Bluefruit.Advertising.setInterval(32, 244);
    // Bluefruit.Advertising.setFastTimeout(30);
    // Bluefruit.Advertising.start(0);
}