#ifndef APP_H
#define APP_H

#include <stdbool.h>
#include "Controllers/FlywheelController.h"
#include "Hardware/Button.h"

// This frequency seemed to provide the best range of operation from the stock motors.
static const uint32_t MOTOR_FREQUENCY = 35000;

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