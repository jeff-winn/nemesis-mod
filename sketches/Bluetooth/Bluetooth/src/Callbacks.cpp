#include <stddef.h>

#include "Callbacks.h"

// Defines the callback which will be executed whenever a bluetooth command has been received.
RemoteCommandReceivedCallback onBluetoothRemoteCommandReceivedCallback;

void SetBluetoothCommandReceivedCallback(RemoteCommandReceivedCallback callback) {  
  onBluetoothRemoteCommandReceivedCallback = callback;
}

void NotifyBluetoothCommandReceived(uint8_t type, uint8_t* data, uint8_t len, uint8_t subtype) {
  if (onBluetoothRemoteCommandReceivedCallback != NULL) {
    onBluetoothRemoteCommandReceivedCallback(type, subtype, data, len);
  }
}