#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <stdint.h>

// Defines the callback method for remote command received notifications.
typedef void (*RemoteCommandReceivedCallback) (const uint8_t type, const uint8_t subtype, const uint8_t* data, const uint8_t len);

// Sets the global callback to be invoked when a bluetooth command has been received.
void SetBluetoothCommandReceivedCallback(RemoteCommandReceivedCallback callback);

// Notifies the application when a bluetooth command has been received.
void NotifyBluetoothCommandReceived(const uint8_t type, const uint8_t* data, const uint8_t len, const uint8_t subtype);

#endif /* CALLBACKS_H */