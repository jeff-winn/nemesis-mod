#include "Callbacks.h"
#include "Log.h"

// Defines the callback which will be executed whenever a bluetooth command has been received.
RemoteCommandReceivedCallback onBluetoothRemoteCommandReceivedCallback;

void SetBluetoothCommandReceivedCallback(RemoteCommandReceivedCallback callback) {  
  onBluetoothRemoteCommandReceivedCallback = callback;
  Log.println("Configured bluetooth callback.");
}

void NotifyBluetoothCommandReceived(uint8_t type, uint8_t* data, uint16_t len, uint8_t subtype) {
  onBluetoothRemoteCommandReceivedCallback(type, data, len, subtype);
}