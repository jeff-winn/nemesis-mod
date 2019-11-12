#include "RemoteCommandReceivedCallback.h"
#include "../Log.h"

RemoteCommandReceivedCallback onBluetoothRemoteCommandReceivedCallback;

void SetBluetoothCommandReceivedCallback(RemoteCommandReceivedCallback callback) {  
  onBluetoothRemoteCommandReceivedCallback = callback;
  Log.println("Configured bluetooth callback.");
}