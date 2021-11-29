#ifndef I2C_CONTROLLER_H
#define I2C_CONTROLLER_H

#define CIRCULAR_BUFFER_INT_SAFE
#include <CircularBuffer.h>
#include "InterruptPin.h"

typedef void (*I2cCommandReceivedCallback)(uint8_t type, uint8_t subtype, uint8_t *data, uint8_t len);

void OnI2cCommandReceivedCallback(int numBytes);
void OnI2cRequestReceivedCallback();

class I2cController {
    public:
        I2cController();
        ~I2cController();

        void init(I2cCommandReceivedCallback callback);
        void clear();

        void runNextPacket();
        void forwardPacket(uint8_t type, uint8_t subtype, uint8_t *data, uint8_t len);

        void onI2cCommandReceived(int numBytes);
        void onI2cRequestReceived();

    private:
        CircularBuffer<uint8_t, 512> *m_rxBuffer;
        CircularBuffer<uint8_t, 512> *m_txBuffer;       
        InterruptPin *m_interrupt;

        volatile uint8_t m_rxCount; // Identifies the number of packets waiting for processing.
        volatile uint8_t m_txCount; // Identifies the number of packets ready to transmit.

        I2cCommandReceivedCallback m_callback;
        
};

extern I2cController I2CBus;

#endif /* I2C_CONTROLLER_H */