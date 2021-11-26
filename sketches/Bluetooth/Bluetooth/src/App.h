#ifndef APP_H
#define APP_H

#include "BLEController.h"

class App {
    public:
        App();

        void init();

        void runOnce();
    
    private:
        BLEController ble;
};

#endif /* APP_H */