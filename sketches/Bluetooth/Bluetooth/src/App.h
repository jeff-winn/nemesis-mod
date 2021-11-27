#ifndef APP_H
#define APP_H

#include <CircularBuffer.h>

#include "BLEController.h"
#include "InterruptPin.h"

class App {
    public:
        App();

        void init();

        void runOnce();
    
        void onI2cRequestReceived();
        void onRemoteCommandReceived(uint8_t type, uint8_t subtype, uint8_t* data, uint8_t len);    
    
    private:
        CircularBuffer<uint8_t, 1024> *txBuffer;
};

extern App Application;

#endif /* APP_H */