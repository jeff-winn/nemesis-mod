#include "RemoteCommandReceivedCallback.h"

RemoteCommandReceivedCallback onBluetoothRemoteCommandReceivedCallback;

void SetBluetoothCommandReceivedCallback(RemoteCommandReceivedCallback callback) {
  onBluetoothRemoteCommandReceivedCallback = callback;
}