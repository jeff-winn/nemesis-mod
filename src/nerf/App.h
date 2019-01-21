#ifndef APP_H
#define APP_H

#include <stdbool.h>
#include "Motor.h"

class App {
    public:
        App();
        
        void init();
        void run();

    private:
        bool m_enabled;
        Motor* m_m1;
        Motor* m_m2;
};

#endif