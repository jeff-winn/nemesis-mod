#include <stddef.h>

#include "Callbacks.h"

// Defines the callback which will be executed whenever a bluetooth command has been received.
RemoteCommandReceivedCallback onBluetoothRemoteCommandReceivedCallback;

void SetBluetoothCommandReceivedCallback(RemoteCommandReceivedCallback callback) {  
  onBluetoothRemoteCommandReceivedCallback = callback;
}

void NotifyBluetoothCommandReceived(const uint8_t type, const uint8_t* data, const uint8_t len, const uint8_t subtype) {
  if (onBluetoothRemoteCommandReceivedCallback != nullptr) {
    onBluetoothRemoteCommandReceivedCallback(type, subtype, data, len);
  }
}