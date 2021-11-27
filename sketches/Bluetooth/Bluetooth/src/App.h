#ifndef APP_H
#define APP_H

#include "BLEController.h"
#include "InterruptPin.h"

class App {
    public:
        App();

        void init();

        void runOnce();
    
        void onRemoteCommandReceived(uint8_t type, uint8_t subtype, uint8_t* data, uint16_t len);    
};

extern App Application;

#endif /* APP_H */