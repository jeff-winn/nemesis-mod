#ifndef I2C_CONTROLLER_H
#define I2C_CONTROLLER_H

#define CIRCULAR_BUFFER_INT_SAFE
#include <CircularBuffer.h>
#include "InterruptPin.h"
#include "Led.h"

typedef void (*I2cCommandReceivedCallback)(const uint8_t type, const uint8_t subtype, const uint8_t* data, const uint8_t len);

void OnI2cCommandReceivedCallback(int numBytes);
void OnI2cRequestReceivedCallback();

class I2cController {
    public:
        I2cController();
        ~I2cController();

        void init(I2cCommandReceivedCallback callback);
        void clear();

        void checkForAsyncCommands();
        void notifyReady();

        void setTransmitCount(uint8_t count);
        void sendPacket(const uint8_t type, const uint8_t subtype, const uint8_t* data, const uint8_t len);

        void onI2cCommandReceived(int numBytes);
        void onI2cRequestReceived();

    protected:
        void incrementPending();
        void decrementPending();

        bool shouldExecuteImmediately(uint8_t type);
        bool shouldInterruptBeSet();
        bool shouldLedBeOn();
        
    private:
        CircularBuffer<uint8_t, 512> *m_rxBuffer;
        CircularBuffer<uint8_t, 512> *m_txBuffer;       
        InterruptPin *m_interrupt;        
        Led *m_led;

        volatile uint8_t m_rxPending;
        volatile uint8_t m_txCount; // Identifies the number of bytes to transmit.

        I2cCommandReceivedCallback m_callback;
        
};

extern I2cController I2CBus;

#endif /* I2C_CONTROLLER_H */