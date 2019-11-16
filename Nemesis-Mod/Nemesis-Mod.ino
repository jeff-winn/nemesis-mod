#include <Arduino.h>
#include "src/bluetooth/RemoteCommandReceivedCallback.h"
#include "src/hardware/Mainboard.h"
#include "src/App.h"
#include "src/BluetoothController.h"
#include "src/Button.h"
#include "src/ConfigurationSettings.h"
#include "src/Log.h"

const uint16_t CLEAR_HOLD_IN_MSECS = 30000;  // 30 seconds
const uint16_t RESET_HOLD_IN_MSECS = 5000;   // 5 seconds
const uint32_t RESET_BUTTON_PIN = 28;

App Application = App();
BluetoothController BLE = BluetoothController();
Button ResetButton = Button(RESET_BUTTON_PIN, true);

void setup() {
    Log.waitForUsbConnection();

    Application.init();
    ResetButton.init();
    BLE.init();

    SetBluetoothCommandReceivedCallback(OnBluetoothCommandReceivedCallback);
    BLE.startAdvertising();
}

// Receives notifications whenever a bluetooth command has been received. 
void OnBluetoothCommandReceivedCallback(uint8_t type, uint8_t* data, uint16_t len, uint8_t subtype) {
    Packet_t packet;
    packet.header.type = type;
    packet.header.subtype = subtype;
    packet.header.len = len;
    packet.body = data;

    Application.onRemoteCommandReceived(packet);
}

void loop() {
    if (ResetButton.isPressed()) {
        handleResetAttempt();
    }
    else {
        Application.run();
    }
}

void handleResetAttempt() {    
    auto started = millis();
    while (ResetButton.isPressed()) {
        MCU.delaySafe(50);
    }

    auto successful = false;
    auto diff = millis() - started;

    if (diff >= CLEAR_HOLD_IN_MSECS) {
        Settings.clear();
        successful = true;
    }
    else if (diff >= RESET_HOLD_IN_MSECS) {
        Settings.resetAuthenticationToken();
        Settings.defaultSettings();
        successful = true;
    }

    if (successful) {
        Application.revokeAuthorization();
        BLE.clearBonds();
    }
}