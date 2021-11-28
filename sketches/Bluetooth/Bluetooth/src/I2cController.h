#ifndef I2C_CONTROLLER_H
#define I2C_CONTROLLER_H

#include <CircularBuffer.h>

void OnI2cDataReceivedCallback(int bytesAvailable);
void OnI2cRequestReceivedCallback();

class I2cController {
    public:
        I2cController();
        ~I2cController();

        void init();

        void onI2cDataReceived(int numBytes);
        void onI2cRequestReceived();

        // Notifies the controller the master device has completed startup.
        void notifyReady();

        // Waits until the master device has completed startup.
        void waitForMaster();

    private:
        CircularBuffer<uint8_t, 1024> *m_buffer;
        volatile bool m_ready; // Identifies whether the master device has indicated it has completed startup.

};

extern I2cController I2CBus;

#endif /* I2C_CONTROLLER_H */