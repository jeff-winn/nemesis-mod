#ifndef REMOTE_COMMAND_RECEIVED_CALLBACK_H
#define REMOTE_COMMAND_RECEIVED_CALLBACK_H

#include <stdint.h>

// Defines the callback method for remote command received notifications.
typedef void (*RemoteCommandReceivedCallback) (uint8_t type, uint8_t* data, uint16_t len);

// Defines the callback which will be executed whenever a bluetooth command has been received.
extern RemoteCommandReceivedCallback onBluetoothRemoteCommandReceivedCallback;

// Sets the global callback to be invoked when a bluetooth command has been received.
void SetBluetoothCommandReceivedCallback(RemoteCommandReceivedCallback callback);

#endif