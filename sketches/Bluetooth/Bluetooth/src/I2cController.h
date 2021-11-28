#ifndef I2C_CONTROLLER_H
#define I2C_CONTROLLER_H

#include <CircularBuffer.h>

typedef void (*I2cCommandReceivedCallback)(uint8_t type, uint8_t subtype, uint8_t *data, uint8_t len);

void OnI2cDataReceivedCallback(int numBytes);
void OnI2cRequestReceivedCallback();

class I2cController {
    public:
        I2cController();
        ~I2cController();

        void init(I2cCommandReceivedCallback callback);

        void onI2cDataReceived(int numBytes);
        void onI2cRequestReceived();

        // Notifies the controller the master device has completed startup.
        void notifyReady();

        // Waits until the master device has completed startup.
        void waitForMaster();

    private:
        CircularBuffer<uint8_t, 512> *m_txBuffer;
        I2cCommandReceivedCallback m_callback;
        
        volatile bool m_ready; // Identifies whether the master device has indicated it has completed startup.

};

extern I2cController I2CBus;

#endif /* I2C_CONTROLLER_H */