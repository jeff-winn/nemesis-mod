#ifndef APP_H
#define APP_H

#include <stdbool.h>
#include "Hardware/FlywheelController.h"
#include "Hardware/Button.h"

class App {
    public:
        App();
        
        void init();
        void run();

    private:
        FlywheelController* m_flywheelController;
        Button* m_revTrigger;

        bool m_enabled;
        void startAll();
        void stopAll();
};

#endif