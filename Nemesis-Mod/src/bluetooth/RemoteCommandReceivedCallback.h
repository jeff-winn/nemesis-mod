#ifndef REMOTE_COMMAND_RECEIVED_CALLBACK_H
#define REMOTE_COMMAND_RECEIVED_CALLBACK_H

#include <stdint.h>

typedef void (*RemoteCommandReceivedCallback) (uint8_t type, uint8_t* data, uint16_t len);

extern RemoteCommandReceivedCallback onBluetoothRemoteCommandReceivedCallback;

void SetBluetoothCommandReceivedCallback(RemoteCommandReceivedCallback callback);

#endif