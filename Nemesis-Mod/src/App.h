#ifndef APP_H
#define APP_H

#include <stdbool.h>
#include "Hardware/Motor.h"
#include "Hardware/Button.h"

class App {
    public:
        App();
        
        void init();
        void run();

    private:
        Motor* m_motor1;
        Motor* m_motor2;
        Button* m_button1;

        bool m_enabled;
        void startAll();
        void stopAll();
};

#endif