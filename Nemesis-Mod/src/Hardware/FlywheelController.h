#ifndef FLYWHEEL_CONTROLLER_H
#define FLYWHEEL_CONTROLLER_H

#include "Motor.h"

enum FlywheelMotor {
    Motor1,
    Motor2
};

class FlywheelController {
    public:
        void init(FlywheelMotor flywheel, uint32_t in1, uint32_t in2);

        void startAll();
        void stopAll();

    private:
        Motor* m_motor1;
        Motor* m_motor2;
};

#endif